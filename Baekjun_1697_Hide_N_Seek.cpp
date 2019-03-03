/*
 * Baekjun 1697 Hide and Seek by BFS
 * retrieved from https://www.acmicpc.net/problem/1697
 * in C++ 14
 */

#include <bits/stdc++.h>
using namespace std;

int dist[2000000] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //setting

    int N, K, num=0;
    cin >>N >> K;

    if(K<N){
        num = N-K;
        cout <<num;
    }

    else{
        queue<int> Q;
        Q.push(N);
        dist[N] = 0;
        int key = 0;
        
        while(!Q.empty())
        {

            key = Q.front();
            Q.pop();

            if(key == K){
                cout << dist[key];
                break;
            }
            int next[3] = {key -1, key+1, 2*key};
            for(auto s: next)
            {
                if(dist[s]==0 && 2*(s)<3*K && s>0){
                    dist[s] = dist[key]+1;
                    Q.push(s);
                }
            }
        }
    }
    return 0;
}
