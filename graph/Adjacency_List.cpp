#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

//邻接表，适应于各种图，不能处理反向边;

struct edge{
    int v;//终点
    int w;//边权
}
int n,m;
vector<edge> e[100005];//边集

void dfs(int u,int fa){
    for (auto ed : e[u]){
        int v = ed.v, w = ed.w;
        if(v == fa) continue;
        printf("%d,%d,%d\n",u,v,w);
        dfs(v,u);
    }
}

signed main(){
    cin>>n>>m;
    for (int i = 1;i <= m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back({b,c});
        e[b].push_back({a,c});
    }
    dfs(1,0);
    return 0;
}