#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

//边集数组
struct edge{
    int u;// 起点
    int v;// 终点
    int w;// 边权
}e[10005];
int vis[10005];
int n,m;
void dfs(int u){
    vis[u] = 1;
    for (int i = 1;i <= m;i++){
        if(e[i].u == u){
            int v = e[i].v,w = e[i].w;
            cout<<u<<" "<<v<<" "<<w<<endl;
            if(vis[v]) continue;
            dfs(e[i].v);
        }
    }
}

signed main(){
    cin>>n>>m;
    for (int i = 1;i <= m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[i] = {a,b,c};
        //e[i] = {b,a,c}; // 若有反向边
    }
    dfs(1);
    return 0;
}