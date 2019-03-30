/*
 * Baekjun 5430 AC solved by deq
 * retrieved from https://www.acmicpc.net/problem/5430
 * in C++ 14
 */



#include <bits/stdc++.h>

using namespace std;

deque<int> tokenize_getline(const string& data, const char delimiter = ' ') {
	deque<int> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(stoi(token));
	}
	return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--){
        //input&init
        string func;
        string lst;
        int n;
        cin>>func>>n>>lst;

        deque<int> deq; //리스트가 들어갈 덱

        lst = lst.substr(1, lst.size()-2); //앞 뒤 괄호 제거
        deq = tokenize_getline(lst, ','); // 콤마로 분리해서 덱에 넣기

        //operation
        //R이 홀수개면 뒤에서 꺼내고 R이 짝수개면 앞에서 꺼내자.
        int Rcnt=0, breakcnt=0;

        for(auto s: func){
            if(s=='R'){
                if(deq.empty())continue;
                Rcnt++;
                continue;
            }
            if(deq.empty()){
                cout<<"error\n";
                breakcnt++;
                break;
            }
            if(Rcnt%2==0)
            {
                deq.pop_front();
                continue;
            }
            deq.pop_back();
        }
        if(breakcnt) continue; //에러면 덱 출력안함

        //출력

        if(deq.size()){
            cout<<'[';
            if(Rcnt%2==0){
                while(deq.size()>1){
                    cout<<deq.front()<<',';
                    deq.pop_front();
                }
            }
            else if(Rcnt%2==1){ //R이 홀수개로 마무리 됐으면 뒤에서부터 출력
                while(deq.size()>1){
                    cout<<deq.back()<<',';
                    deq.pop_back();
                }
            }
            cout<<deq.front()<<"]\n";
        }
        else{cout<<"[]\n";}

    }
    return 0;
}

/*
7
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]
RRRDRDRDDRRRDRRD
9
[1,2,3,4,5,6,7,8,9]
R
0
[]
DRRRRRR
1
[1]
*/

