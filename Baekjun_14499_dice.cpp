/*
 * Baekjun 14499 dice
 * retrieved from https://www.acmicpc.net/problem/14499
 * in C++ 14
 */

#include <bits/stdc++.h>
using namespace std;

int aoq[23][23];



int main()
{
    int n, m,x,y,k,tmp;
    cin>>n>>m>>x>>y>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> aoq[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << aoq[i][j]<<' ';
        }
        cout<<'\n';
    }
    int bot, top, l, r, fr, ba;
    bot=0, top=0, fr=0, ba=0, l=0, r=0;

    for(int i=0; i<k; i++){
        cin >> tmp;
        if(tmp==1){
        /*if right roll

        first check if we can roll right
        if can't , continue

        else
        new bot = cur right
        new top = cur left
        new l = cur bot
        new r = cur top
        */
            if(y+1>=m)continue;
            y++;
            int nb = r;
            int nt = l;
            l = bot;
            r = top;
            bot = nb;
            top = nt;

            if(!aoq[x][y]){
                aoq[x][y] = bot;
            }
            else{
                bot = aoq[x][y];
                aoq[x][y] = 0;
            }
            cout<<"> [top/bot/fr/ba/l/r]"<<top<<' '<<bot<<' '<<fr<<' '<<ba<<' '<<l<<' '<<r<<'\n';
            //cout<<top<<'\n';
        }
        else if(tmp==2){
        /*if left roll
        new bot = cur left
        new top = cur right
        new l = cur top
        new r = cur bot
        */
            if(y-1<0)continue;
            y--;
            int nb = l;
            int nt = r;
            l = top;
            r = bot;
            bot = nb;
            top = nt;

            if(!aoq[x][y]){
                aoq[x][y] = bot;
            }
            else{
                bot = aoq[x][y];
                aoq[x][y] = 0;
            }
                cout<<"< [top/bot/fr/ba/l/r]"<<top<<' '<<bot<<' '<<fr<<' '<<ba<<' '<<l<<' '<<r<<'\n';
            //cout<<top<<'\n';
        }
        else if(tmp==3){
        /*if front roll
        new bot = cur front 새로운 바텀은 항상 굴리는 방향과 같다.
        new top = cur back
        new front = cur top
        new back = cur
        */
            if(x-1<0)continue;
            x--;
            int nb = fr;
            int nt = ba;
            fr = top;
            ba = bot;
            bot = nb;
            top = nt;

            if(!aoq[x][y]){
                aoq[x][y] = bot;
            }
            else{
                bot = aoq[x][y];
                aoq[x][y] = 0;
            }
            cout<<"^ [top/bot/fr/ba/l/r]"<<top<<' '<<bot<<' '<<fr<<' '<<ba<<' '<<l<<' '<<r<<'\n';
            //cout<<top<<'\n';
        }
        else if(tmp==4){
        /*if back roll
        new bot = cur back 새로운 바텀은 항상 굴리는 방향과 같다.
        new top = cur front
        new front = cur bot
        new back = cur top
        */
            if(x+1>=n)continue;
            x++;
            int nb = ba;
            int nt = fr;
            ba = top;
            fr = bot;
            bot = nb;
            top = nt;

            if(!aoq[x][y]){
                aoq[x][y] = bot;
            }
            else{
                bot = aoq[x][y];
                aoq[x][y] = 0;
            }
            //cout<<top<<'\n';
            cout<<"v [top/bot/fr/ba/l/r]"<<top<<' '<<bot<<' '<<fr<<' '<<ba<<' '<<l<<' '<<r<<'\n';
        }
    }

    return 0;
}
