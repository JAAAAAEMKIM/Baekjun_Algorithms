#include <bits/stdc++.h>
using namespace std;

int board[107][107];
int body[107][107];
int tlist[107];
char dirlist[107];
int dx[4] = {1,0,-1,0}; //처음에 오른쪽, 시계방향 회전
int dy[4] = {0,1,0,-1}; //오른회전 기준. (D)
#define X first
#define Y second

int main(){
    int n, apple, r, c;
    cin >>n>>apple;
    for(int i=0; i<apple; i++){
        cin >>r>>c;
        board[r][c] = 1;
    }
    int turn;
    cin>>turn;
    for(int i=0; i<turn; i++){
        cin>>tlist[i]>>dirlist[i];
    }

    for(int k=1; k<=n; k++){
        for(int p=1; p<=n; p++)
            cout<<board[k][p]<<' ';
        cout<<'\n';
    }


    //initial state
    int t=0;
    int x=1, y=1;
    int dir = 0;
    queue<pair<int,int> > Q;
    body[1][1]=1;
    int t_ndx = 0;
    Q.push({x, y});

    while(!Q.empty()){
        pair<int,int> cur_head = Q.back();

        cout<<"\"body\""<<' '<<"t :"<<t<<'\n';
        for(int k=1; k<=n; k++){
            for(int p=1; p<=n; p++){
                cout<<body[k][p]<<' ';}
            cout<<'\n';
        }

        if(t==tlist[t_ndx]){
            if(dirlist[t_ndx]=='D'){
                dir=(dir+1)%4;
            }
            else if(dirlist[t_ndx]=='L'){
                dir=(dir+3)%4;
            }
            t_ndx++;
        }
        //if t in tlist{
        //if dirlist[i] = D, dir++ if L dir--}

        int nx = cur_head.X+dx[dir];
        int ny = cur_head.Y+dy[dir];
        //nx = prevhead.X + dx[dir];
        //ny = prevhead.Y + dy[dir];

        if(nx<1 || nx>n || ny<1 ||ny>n){
            cout<<t+1;
            break;
        }
        //if wall: break, return t+1; 넣을 때 체크
        if(body[ny][nx]){
            cout<<t+1;
            break;
        }
        //if body, break, return t+1; 넣을 때 체크

        //not wall nor body
        Q.push({nx,ny});
        body[ny][nx]=1;
        //newhead = {nx,ny},
        //Q.push newhead, body+newhead

        if(board[ny][nx]){//apple
            apple--;
            board[ny][nx]=0;
            /*cout<<"apple: "<<apple<<'\n';
            if(!apple){
                cout<<t+1;
                break;
            }*/
            t++;
            continue;
        }
        //if apple, apple--; continue;
            //if apple=0, break, return t+1;
        else if(!board[ny][nx]){
            int tx, ty;
            tx = Q.front().X;
            ty = Q.front().Y;
            body[ty][tx]=0;
            Q.pop();
        }
        //if !apple, Q.pop tail; body-tail;
        t++;
        //t++
    }
}

/*

*/

