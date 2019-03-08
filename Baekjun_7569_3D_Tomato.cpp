/*
 * Baekjun 7569 3D-tomato by BFS
 * retrieved from https://www.acmicpc.net/problem/7569
 * in C++ 14
 */

#include <bits/stdc++.h>
using namespace std;

int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

queue<tuple<int,int,int>> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, H, daisy=0;
    int zerocnt = 0;
    cin >> M>> N>> H;
    int tomato[H][N][M];
    int day[H][N][M];
    for(int i=0; i<H; i++) // z
    {
        for(int j=0; j<N; j++) // y
        {
            for(int k=0; k<M; k++) // x
            {
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] ==0){
                    zerocnt++;
                }
                else if(tomato[i][j][k] ==1){
                    tuple<int,int,int> temp (k,j,i);
                    Q.push(temp);
                }
                day[i][j][k] =0;
            }
        }
    }
    //Start BFS
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for(int dir=0; dir<6; dir++)
        {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if(nx<0 or nx>=M or ny<0 or ny>=N or nz<0 or nz>=H or day[nz][ny][nx]) continue;
            if(tomato[nz][ny][nx]== 0 && !day[nz][ny][nx]){
                tuple<int,int,int> temp = make_tuple(nx, ny, nz);
                Q.push(temp);
                day[nz][ny][nx] = day[get<2>(cur)][get<1>(cur)][get<0>(cur)] +1;
                daisy = max(daisy, day[nz][ny][nx]);
                zerocnt--;
                continue;
            }
        }
    }
    if(zerocnt)cout<<-1;
    else
        cout << daisy;
    return 0;
}
