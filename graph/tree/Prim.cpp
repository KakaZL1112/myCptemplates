#include <bits/stdc++.h>
using namespace std;
#define INF 0x7f7f7f7f
const int N = 2e5+5;

struct edge
{
    int v,w;
};

int d[N];
vector<edge> e[N];
int vis[N];
int ans = 0;
int cnt = 0;
int n,m;


priority_queue<pair<int,int>> q;
bool prim(int s){
    for (int i = 1;i <= n;i++) d[i] = INF;
    d[s] = 0; q.push({0,s});
    while(q.size()){
        int u = q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        ans+=d[u];
        cnt++;
        for (auto ed:e[u]){
            int v = ed.v, w = ed.w;
            if(d[v] > w){
                d[v] = w;
                q.push({-d[v],v});
            }
        }
    }
    return cnt == n;
}


int main(){
    cin>>n>>m;
    for (int i = 1;i <= m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back({b,c});
        e[b].push_back({a,c});
    }
    if(prim(1)){
        cout<<ans<<endl;
    }else{
        cout<<"orz"<<endl;
    }
}

