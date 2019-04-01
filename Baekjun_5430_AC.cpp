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

	while (getline(ss, token, delimiter)) {	// getline 안의 delimiter는 나누는 기준. 나눠진 string을 token에 저장.
		result.push_back(stoi(token));	// 만들어진 token이 있다면(여기서는 숫자) int형으로 덱에 저장. 
	}					// http://www.cplusplus.com/reference/string/string/getline/
	return result;
}	// string stream을 통해 ','를 기준으로 나눠 하나씩 덱에 넣는 함수 (찾아와서 수정함)


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--){
        //input&init
        string func;	// R과 D로 이뤄진 문자열
        string lst;	// 입력받은 리스트
        int n;		// 원소 수
        cin>>func>>n>>lst;

        deque<int> deq; //리스트가 들어갈 덱

        lst = lst.substr(1, lst.size()-2); //앞 뒤 괄호 제거
        deq = tokenize_getline(lst, ','); // 콤마로 분리해서 덱에 넣기

        // operation
        // R이 홀수개면 뒤에서 꺼내고 R이 짝수개면 앞에서 꺼내자.
        int Rcnt=0, breakcnt=0;	//R의 갯수세기; break condition

        for(auto s: func){
            if(s=='R'){
                if(deq.empty())continue;	// R이고 덱이 비었으면 에러가 아님-> continue
                Rcnt++;				// 그냥 R이면 갯수 세주기
                continue;
            }
            if(deq.empty()){			// D이고 덱이 빈 경우
                cout<<"error\n";		// 에러 출력
                breakcnt++;			// 탈출조건=1
                break;				// 탈출
            }
            if(Rcnt%2==0)
            {
                deq.pop_front();
                continue;
            }
            deq.pop_back();
        }
        if(breakcnt) continue; // 에러면 덱 출력안함-> 다음 테스트 케이스 바로 ㄱ

        //출력
        if(deq.size()){		// 덱에 원소가 있으면
            cout<<'[';
            if(Rcnt%2==0){	// R이 짝수개였으면 앞부터
                while(deq.size()>1){
                    cout<<deq.front()<<',';
                    deq.pop_front();
                }
            }
            else if(Rcnt%2==1){ // R이 홀수개로 마무리 됐으면 뒤에서부터 출력
                while(deq.size()>1){
                    cout<<deq.back()<<',';
                    deq.pop_back();
                }
            }
            cout<<deq.front()<<"]\n";	// 마지막 남은거랑 괄호닫기
        }
        else{cout<<"[]\n";}	// 덱에 원소가 없으면
    }
    return 0;
}

// Memory 3240KB; Time 60ms

// 아래는 돌려본 테스트케이스
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

