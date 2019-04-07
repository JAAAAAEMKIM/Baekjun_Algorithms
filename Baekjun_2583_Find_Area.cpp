/*
 * Baekjun 2583 7 Find Area by BFS
 * retrieved from https://www.acmicpc.net/problem/2583
 * in C++ 14
 */


#include <bits/stdc++.h>
using namespace std;


#define X first
#define Y second

int monun[100][100];
int vis[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int M, N, K;
    cin >> M >> N >> K;

    for(int i=0; i<K; i++){
        int begin_x, begin_y, end_x, end_y;
        cin >> begin_x>>begin_y>>end_x>>end_y;
        for(int j=begin_x; j<end_x; j++){
            for(int k=begin_y; k<end_y; k++){
                monun[k][j] = 1;
            }
        }
    }
    // Initialize areas to an array

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout<<monun[i][j]<<' ';
            if(monun[i][j]){
                vis[i][j] = 2;
            }
        }
        cout<<'\n';
    }
    // Check input
    
    vector<int> cnt_list; // To store areas
    int nemos=0;  // To count how many parts
    
    //BFS preparation
    queue<pair<int,int> > Q;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(monun[i][j] or vis[i][j])continue; // Wall or already visited

            nemos++;  // Found a part
            int cnt = 1;
            Q.push({j,i});
            vis[i][j] = 1;
            
            // Start BFS from the explored node
            while(!Q.empty()){
                auto cur = Q.front();
                Q.pop();

                for(int dir=0; dir<4; dir++){
                    int nx = dx[dir]+cur.X;
                    int ny = dy[dir]+cur.Y;

                    if(nx<0 or nx>N-1 or ny<0 or ny>M-1) continue;
                    if(monun[ny][nx] or vis[ny][nx])continue;

                    vis[ny][nx] = 1;
                    Q.push({nx, ny});
                    cnt++;
                    
                    // Check by visualization
                    cout<<"cnt: "<<cnt<<" X, Y: "<<nx<<' '<<ny<<'\n';
                    for(int i=0; i<M; i++){
                        for(int j=0; j<N; j++){
                            cout<<vis[i][j]<<' ';
                        }
                        cout<<'\n';
                    }
                }
            }
            cnt_list.insert(cnt_list.begin(), cnt);
            cout<<"insert : "<<cnt<<'\n';
        }
    } // End of BFS
    
    // Output
    cout<<nemos<<'\n';
    sort(cnt_list.begin(), cnt_list.end());
    for(auto s:cnt_list){
        cout<<s<<' ';
    }
    return 0;
}

/*
Test cases

5 6 1
0 0 3 5

5 7 3
0 2 4 4
1 1 2 5
4 0 6 2

*/
