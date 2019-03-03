/*
 * Baekjun 7576 tomato solved by BFS
 * retrieved from https://www.acmicpc.net/problem/7576
 * in C++ 14
 */

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //setting

    // Init
    int M, N, result=0; // (M: x-axis: j) ; (N: y-axis: i)
    int zero_counter = 0;
    cin >>M >>N;
    int box[N][M];
    int dist[N][M];
    queue<pair<int,int>> Q;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> box[i][j];
            dist[i][j] = -1;
            if(box[i][j] == 1){
                Q.push({j,i});
                dist[i][j] =0;
            }
            else if(box[i][j] == 0)
                zero_counter++;         //check the number of the immatures
        }
    }

    //BFS operation
    while(!Q.empty()){
        auto cur = Q.front();       //current coordinate
        Q.pop();

        for(int dir=0; dir<4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx<0 or nx >=M or ny<0 or ny>=N) continue;       // out of range
            if(dist[ny][nx]!=-1 or box[ny][nx] == -1) continue;      // already visited or Not a tomato
            
            dist[ny][nx] = dist[cur.second][cur.first] + 1;     // mark distance
            Q.push({nx,ny});
            zero_counter--;                                     // How many immature tomatoes left
            result = max(dist[ny][nx], result);
        }
    }
    if(!zero_counter)                               // if there's no zero
        cout<<'\n'<<"result is: "<<result<<'\n';    // = Available sample
    else
        cout << '\n'<<"result is: "<<-1<<'\n';      // print -1 if unavailable
    return 0;
}
