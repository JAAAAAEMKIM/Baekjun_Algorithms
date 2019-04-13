/*
 * Baekjun 10026 RG blind
 * retrieved from https://www.acmicpc.net/problem/10026
 * in C++ 14
 */

#include <bits/stdc++.h>
using namespace std;

int general[100][100];
int blind[100][100];
int visg[100][100];
int visb[100][100];

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

#define X first
#define Y second

stack<pair<int,int> > Q;

int main(){
    int n;
    cin >> n;
    string tmp;
    for(int i=0; i<n; i++){
        getline(cin, tmp);
        while(!tmp.size()){
            getline(cin, tmp);
        }
        for(int j=0; j<n; j++){
            if (tmp[j] == 'R'){
                general[i][j] = 0;
                blind[i][j] = 1;
            }
            else if(tmp[j] == 'G'){
                general[i][j] = 1;
                blind[i][j] = 1;
            }
            else{
                general[i][j] = blind[i][j] = 2;
            }
        }
    }
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<general[i][j]<< ' ';
        cout<<'\n';
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<blind[i][j]<< ' ';
        cout<<'\n';
    }*/

    int cntg = 0;
    int cntb = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visg[i][j])continue;

            int col = general[i][j];
            cntg++;
            visg[i][j]=1;

            Q.push({j,i});
            while(!Q.empty()){
                auto cur = Q.top();
                Q.pop();

                for(int dir=0; dir<4; dir++){
                    int nx = dx[dir]+cur.X;
                    int ny = dy[dir]+cur.Y;

                    if(nx<0 || nx>n-1 || ny<0 || ny>n-1)continue;
                    if(visg[ny][nx]) continue;

                    if(general[ny][nx]==col){
                        visg[ny][nx] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visb[i][j])continue;

            int col = blind[i][j];
            cntb++;
            visb[i][j]=1;
            
            Q.push({j,i});
            while(!Q.empty()){
                auto cur = Q.top();
                Q.pop();

                for(int dir=0; dir<4; dir++){
                    int nx = dx[dir]+cur.X;
                    int ny = dy[dir]+cur.Y;

                    if(nx<0 || nx>n-1 || ny<0 || ny>n-1)continue;
                    if(visb[ny][nx]) continue;

                    if(blind[ny][nx]==col){
                        visb[ny][nx] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }

    cout<<cntg<<'\n'<<cntb;
    return 0;
}
