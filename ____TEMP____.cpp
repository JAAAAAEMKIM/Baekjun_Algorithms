#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //setting

    vector<int> v1;
    int n, m, tmp;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        v1.insert(v1.end(), tmp);
    }
    sort(v1.begin(), v1.end());
    for(auto s:v1){
        cout<<s;
    }
    cin>>m;
    queue<int> Q;
    int st=0; int en=n-1; int mid = (en+st)/2;
    for(int j=0; j<m; j++){
        cin >> tmp;
        Q.push(tmp);
        //auto pos = find(v1.begin(), v1.end(), tmp);
    }
    Q.push(0);
    int goal = Q.front();
    Q.pop();
    while(!Q.empty()){
        //cout<<'\n'<<goal<<' '<<st<<' '<<en<<' '<<mid<<' ';
        int key = *(v1.begin()+mid);
        //cout<<key;
        if(en<st){
            cout<<0<<'\n';
            en=n-1;
            st=0;
            mid = (en+st)/2;
            goal = Q.front();
            Q.pop();
        }
        else if(key == goal){
            cout<<1<<'\n';
            en=n-1;
            st=0;
            mid = (en+st)/2;
            goal = Q.front();
            Q.pop();
        }
        else if(goal> key){
            st = mid +1;
            mid = (st+en)/2;
            continue;
        }
        else if(goal< key){
            en = mid-1;
            mid = (st+en)/2;
            continue;
        }
    }
    return 0;
}
