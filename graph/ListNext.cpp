#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

//链式邻接表，适应于各种图，能处理反向边;

struct edge{
    int v;//终点
    int w;//边权
    int ne;//下一条边的编号
};
int n,m;
edge e[100005];//边集
int idx,h[100005];//点的第一条出边

void add(int u,int v,int w){
  e[++idx].v=v; e[idx].w=w;  
  e[idx].ne=h[u]; h[u]=idx;
}

void dfs(int u,int fa){
    for (int i = h[u];~i;i = e[i].ne){
        int v = e[i].v,w = e[i].w;
        if(v == fa) continue;
        printf("%d,%d,%d,\n",u,v,w);
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