/*
 * Baekjun 1158 Joseph with Queue and list
 * retrieved from https://www.acmicpc.net/problem/1158
 * in C++ 14
 */

#include <bits/stdc++.h>
using namespace std;

//with Queue
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >>N >> M;

    queue<int> Q;
    queue<int> R;

    for(int i=1; i<=N; i++){
        Q.push(i);
    }
    cout << "<";

    while(!Q.empty())
    {
        for(int i=0; i<M-1; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }
        R.push(Q.front());
        Q.pop();
    }
    while(R.size()!=1){
        cout << R.front() <<", ";
        R.pop();
    }
    cout << R.front() <<'>';

    return 0;
}

/**with List
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >>N >> M;
    int _size = N;

    int v1[N];
    for(int i=0; i<=N; i++)
        v1[i] = i;

    cout << "<";
    int order = 0;

    while(_size)        //initially N
    {
        int offset = M;
        while(offset)
        {
            order++;
            if(order > N)
                order = order%N;
            if(v1[order]!=0)
                offset --;
        }
        if(1<_size)
            cout << v1[order] <<", ";
        else
            cout << v1[order]<< ">";
        v1[order] = 0;
        _size--;
    }
    return 0;
}
**/
