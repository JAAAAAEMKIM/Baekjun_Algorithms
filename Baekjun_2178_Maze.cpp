/*
 * Baekjun 2178 Picture solved by BFS
 * retrieved from https://www.acmicpc.net/problem/2178
 * in C++ 14
 */
 
 #include <bits/stdc++.h>

using namespace std;

int maze[102][102];
int vis[102][102];
int dist[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int,int>> Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //setting

    //init
    int N, M, endflag = 0;
    string row;
    cin >>N >> M;
    for(int i=0; i<N; i++){
        cin>>row;
        for(int j=0; j<M; j++){
            string subrow = row.substr(j,1);
            maze[i][j] = stoi(subrow);
        }
    }
    // check maze input
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
                cout<<maze[i][j]<<' ';
        }
        cout<<'\n';
    }

    //preparation
    int depth = 0;
    int nx, ny;

    //operation
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(maze[i][j]==0 or vis[i][j])
                continue;
            // Found!
            else{
                vis[i][j] = 1;
                dist[i][j] = ++depth;
                Q.push({i,j});

                // Start BFS
                int w = 0;
                while(!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();

                    for(int dir = 0; dir<4; dir++){
                        nx = cur.first + dx[dir];
                        ny = cur.second + dy[dir];

                        if(nx <0 or nx >=N or ny <0 or ny >=M)
                            continue;

                        if(maze[nx][ny] && !vis[nx][ny]){
                            Q.push({nx,ny});
                            dist[nx][ny] = dist[cur.first][cur.second] +1;
                            vis[nx][ny] = 1;
                        }
                    };   // end of for loop
                }       // end of while loop
                        //end of BFS
                endflag = 1;
                break;
            }
            if(endflag)break;
        }
        if(endflag)break;
    }
    cout <<dist[N-1][M-1] <<'\n';

    return 0;
}
