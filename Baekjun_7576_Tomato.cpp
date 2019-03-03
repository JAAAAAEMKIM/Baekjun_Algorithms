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

    int M, N, result=0; // M: x-axis: j ; N: y-axis: i
    int zero_counter = 0;
    cin >>M >>N;
    int box[N][M];
    int vis[N][M];
    int dist[N][M];
    queue<pair<int,int>> Q;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> box[i][j];
            vis[i][j] = 0;
            dist[i][j] = 0;
            if(box[i][j] == 1){
                Q.push({j,i});
                vis[i][j] =1;
            }
            else if(box[i][j] == 0)
                zero_counter++;
        }

    }

    for(int i = 0; i< N; i++){
        for(int j=0; j<M; j++)
            cout<<box[i][j]<<' ';
        cout<<'\n';
    }

    //BFS operation
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();

        for(int dir=0; dir<4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx<0 or nx >=M or ny<0 or ny>=N) continue;
            if(vis[ny][nx] or box[ny][nx] == -1) continue;

            vis[ny][nx] = 1;
            dist[ny][nx] = dist[cur.second][cur.first] + 1;
            Q.push({nx,ny});
            zero_counter--;
            result = max(dist[ny][nx], result);
        }
    }
    if(!zero_counter)
        cout<<'\n'<<"result is: "<<result<<'\n';
    else
        cout << '\n'<<"result is: "<<-1<<'\n';

    for(int i = 0; i< N; i++){
        for(int j=0; j<M; j++)
            cout<<dist[i][j]<<' ';
        cout<<'\n';
    }

    for(int i = 0; i< N; i++){
        for(int j=0; j<M; j++)
            cout<<vis[i][j]<<' ';
        cout<<'\n';
    }

    /*
    for(int i = 0; i< N; i++){
        for(int j=0; j<M; j++){
            if(box[i][j]==1)
        }
    }*/

    return 0;
}
