#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

//链式邻接表，适应于各种图，能处理反向边;

struct edge{
    int u;//起点
    int v;//终点
    int w;//边权
};
int n,m;
vector<edge> e;//边集
vector<int> h[100005];//head表头数组，点的所有出边;

void add(int a,int b,int c){
    e.push_back({a,b,c});
    h[a].push_back(e.size()-1);
}

void dfs(int u,int fa){
    for (int i = 0;i<h[u].size();i++){
        int j = h[u][i];
        int v = e[j].v,w = e[j].w;
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
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,0);
    return 0;
}