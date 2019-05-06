#include <bits/stdc++.h>

using namespace std;

struct edge{
    int cost;
    int from;
    int to;
};

struct cmp{
    bool operator()(edge a, edge b){
        return a.cost>b.cost;
    }
};

vector<edge> roads2[1007];
vector<edge> roads[1007]; // vector<edge>가 1007개
priority_queue<edge, vector<edge>, cmp> pq;
int dist_front[1007];   //distance toward x
int dist_back[1007];    //distance from x
int vis[2007];

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);

    //init
    int n, m, x;
    int a, b, c;
    cin >>n>>m>>x;
    for(int i=1; i<=m; i++){
        cin>>a>>b>>c;
        roads[a].push_back({c, a, b});//push a road which starts from a into roads[a]
        roads2[b].push_back({c, a, b});
    }
    for(int i=1; i<=n; i++){
        dist_back[i] = 1e6+7;
        dist_front[i] = 1e6+7;
    }

    //second graph(from x to home)
    //vis[1~1000], dist_back[1~1000](dist from x to home)
    pq.push((edge){0,x,x});
    vis[x]=1;
    dist_back[x]=0;
    edge cur;
    while(!pq.empty()){
        cur = pq.top();
        pq.pop();
        vis[cur.to]=1; //뽑은 노드 방문 체크

        for(int i=0; i<roads[cur.to].size();i++){
            if(vis[roads[cur.to][i].to])continue;
            if(dist_back[roads[cur.to][i].to]<=dist_back[cur.to]+roads[cur.to][i].cost)continue;

            dist_back[roads[cur.to][i].to]=dist_back[cur.to]+roads[cur.to][i].cost;
            pq.push({dist_back[roads[cur.to][i].to], cur.to, roads[cur.to][i].to});
            //roads[cur.to][i].to 는 현재노드[cur.to]에서 시작하는 ith road의 목적지
        }
    }

    //first graph(from home to x)
    //vis[1001~2000], dist_front[1~1000](dist from home to x)
    //to --> from
    pq.push((edge){0,x,x});
    vis[x+1000]=1;
    dist_front[x]=0;

    while(!pq.empty()){
        cur = pq.top();
        pq.pop();
        vis[cur.from+1000]=1; //뽑은 노드 방문 체크

        for(int i=0; i<roads2[cur.from].size();i++){
            if(vis[roads2[cur.from][i].from+1000])continue;
            if(dist_front[roads2[cur.from][i].from]<=dist_front[cur.from]+roads2[cur.from][i].cost)continue;

            dist_front[roads2[cur.from][i].from]=dist_front[cur.from]+roads2[cur.from][i].cost;
            pq.push({dist_front[roads2[cur.from][i].from], roads2[cur.from][i].from, cur.from});
            //roads[cur.to][i].to 는 현재노드[cur.to]에서 시작하는 ith road의 목적지
        }
    }
    for(int i=1; i<=n; i++){
        dist_back[i]+=dist_front[i];
    }
    cout<<*max_element(dist_back, dist_back+n+1);

    return 0;
}
