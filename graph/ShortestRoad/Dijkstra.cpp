#include <bits/stdc++.h>
#define endl '\n'
#define INF 0x7f7f7f7f
const int N = 100005;
using namespace std;

struct edge{
    int v;
    int w;
};
int n,m,s;
vector<edge> e[N];
int d[N],vis[N],pre[N];
//不能处理负边权 复杂度（n^2+m) = n^2;  改为队列后 为 n*log2m

priority_queue<pair<int,int>> q; // 将边权处理为负值，在优先队列中 值越小便越靠前 队列就优先处理边权小的

void dijkstra(int s){
    for (int i = 0;i <= n;i++) d[i] = INF;
    d[s] = 0;q.push({0,s});
    while(q.size()){
        auto t = q.top();q.pop();
        int u = t.second;
        if(vis[u]) continue;
        vis[u] = 1;
        for (auto ed:e[u]){
            int v = ed.v,w=ed.w;
            if(d[v] > d[u]+w){
                d[v]= d[u]+w;
                pre[v] = u;//记 录 前 驱 点；
                q.push({-d[v],v});
            }
        }
    }
}

void dfs_path(int u){
    if(u == s) {cout<<u<<" ";return;}
    dfs_path(pre[u]);
    cout<<u<<" ";
} //路径记录


signed main(){
    cin>>n>>m>>s;
    for (int i = 0;i < m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back({b,c});
    }
    dijkstra(s);
    for (int i = 1;i <= n;i++) cout<<i<<":"<<d[i]<<" ";
}