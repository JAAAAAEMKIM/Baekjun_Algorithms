/*
 * Baekjun 2667 block address
 * retrieved from https://www.acmicpc.net/problem/2667
 * in C++ 14
 * FAILED
 */

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

// directions
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1}; 

int cnt; // the number of blocks

queue<pair<int,int>> Q;
vector<int> v1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //setting

    //input
    int n;
    cin >>n;
    int _map[n][n];
    int vis[n][n];

    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        while(temp.size()==0)
            cin>>temp;
            //buffer
        for(int j=0; j<n; j++){
            int dat = stoi(temp.substr(j,1), nullptr, 10);
            _map[i][j]=dat;
            vis[i][j] = 0;
        }
    }
    /*
    //check input
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << _map[i][j]<<' ';
        }cout << '\n';
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << vis[i][j]<<' ';
        }cout << '\n';
    }*/
    // input OK

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(_map[i][j]==0 or vis[i][j]) continue;
            
            // if found
            int num=1;
            cnt++;
            Q.push({j,i}); // push (x ,y)
            vis[i][j] +=cnt;
            
            // Start BFS
            while(!Q.empty()){
                auto cur = Q.front();
                Q.pop();

                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx<0 or nx>=n or ny<0 or ny>=n)continue;
                    if(vis[ny][nx] or _map[ny][nx]==0)continue;

                    vis[ny][nx] +=cnt;
                    Q.push({nx,ny});
                    num++;
                }
            }
            v1.insert(v1.end(), num);
        }
    }

    sort(v1.begin(),v1.end());
    cout<<cnt<<'\n';
    for(auto i: v1)
        cout << i<<'\n';

    return 0;
}
