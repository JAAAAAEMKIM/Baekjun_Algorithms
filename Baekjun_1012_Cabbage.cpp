/*
 * Baekjun 1012 Cabbage solved by BFS
 * retrieved from https://www.acmicpc.net/problem/1012
 * in C++ 14
 */

 #include <bits/stdc++.h>
 using namespace std;

 int farm[54][54];
 int vis[54][54];

 int dx[4] = {1,0,-1,0};
 int dy[4] = {0,1,0,-1};

 queue<pair<int,int>> Q;

 int main()
 {
     ios::sync_with_stdio(0);
     cin.tie(0);
     //setting

     //init
     int T, N, M, K, _X, _Y;
     cin >>T;
     while(T--)
     {
         int num = 0;
         cin >> M >> N >> K;

         for(int i=0; i<N; i++)
            for(int j=0; j<M; j++){
                farm[i][j] =0;
                vis[i][j] = 0;
                // Empty farm
                }
         for(int i=0; i<K; i++)
         {
             cin >> _X >> _Y;
             farm[_Y][_X] = 1;
         } // input cabbages into the farm

         /*//check input
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cout << farm[i][j] <<' ';
            }
            cout <<'\n';}*/

         for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(vis[i][j] or !farm[i][j]) continue;

                Q.push({i,j});
                vis[i][j] = 1;
                //cout << "coordinate: " << j<<' '<<i<<'\n';
                num++;

                while(!Q.empty()){
                    auto cur = Q.front();Q.pop();

                    for(int dir=0; dir<4; dir++){
                        int nx = cur.second + dx[dir];
                        int ny = cur.first + dy[dir];

                        if(nx<0 or nx>=M or ny<0 or ny>=N) continue;
                        if(vis[ny][nx] or farm[ny][nx]!= 1)continue;
                            Q.push({ny,nx});
                            vis[ny][nx] =1;
                    }
                }
            }
        }
        cout << num <<'\n';
    }
    return 0;
}
