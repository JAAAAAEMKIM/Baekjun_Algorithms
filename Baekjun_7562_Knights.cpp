/*
 * Baekjun 7562 Knights
 * retrieved from https://www.acmicpc.net/problem/7562
 * in C++ 14
 */


#include <bits/stdc++.h>
using namespace std;


int checkerboard[300][300];
int dx[8]={-2,-2,-1,-1, 1, 1, 2, 2};
int dy[8]={ 1,-1, 2,-2, 2,-2, 1,-1};  // A move of a knight

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, l, x;

    cin>>T;
    while(T--){
        cin >>l;
        vector<int> begin_node, end_node; // A node={x, y, depth}
        int bx, by, ex, ey;
        cin >> bx>>by;
        begin_node.insert(begin_node.end(), bx);
        begin_node.insert(begin_node.end(), by);
        begin_node.insert(begin_node.end(), 0);
        cin >> ex>> ey;
        if(bx==ex && by == ey){
            cout<<0<<'\n';
            continue;
        }
        end_node.insert(end_node.end(), ex);
        end_node.insert(end_node.end(), ey);
        end_node.insert(end_node.end(), 0);

        int vis[l][l];
        for(int i=0; i<l; i++){
            for(int j=0; j<l; j++)
            {
                vis[i][j]=0;
            }
        }

        queue<vector<int>> Q;

        Q.push(begin_node);
        vis[begin_node[0]][begin_node[1]]=1;  // Mark as visited
        int breakp = 0;  // Break trigger

        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();

            if(breakp)break;

            for(int dir = 0; dir<8; dir++){
                vector<int> tmp;

                int nx = cur[0] + dx[dir];
                int ny = cur[1] + dy[dir];
                tmp.insert(tmp.end(), nx);
                tmp.insert(tmp.end(), ny);
                tmp.insert(tmp.end(), cur[2]+1);

                if(nx == end_node[0] && ny == end_node[1]){
                    cout<<tmp[2]<<'\n';
                    breakp++;
                    break;
                }
                if(nx<0 or nx>l-1 or ny<0 or ny>l-1)continue;
                if(vis[ny][nx])continue;

                Q.push(tmp);
                vis[ny][nx]=1;
            }
        }
    }

    return 0;
}

/*
test cases
5
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
8
1 0
0 1
8
0 0
3 3
*/

/*
answers
5
28
0
2
2
*/
