//到树的点的最远距离最近
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
struct edge{
    int v,w;
};

vector<edge> e[N];
int d1[N],d2[N],up[N],p1[N];
//向下找向下的
int dfs_d(int u,int fa){
    d1[u] = 0;
    d2[u] = 0;
    for (auto ed:e[u]){
        int v = ed.v;
        int w = ed.w;
        if(v == fa) continue;
        int d = dfs_d(v,u)+w;
        if(d >= d1[u]) d2[u] = d1[u],d1[u] = d,p1[u] = v;
        else if(d > d2[u]) d2[u] = d;
    }

    return d1[u];
}

//找上的最长路径
void dfs_u(int u,int fa){
    for(auto ed:e[u]){
        int v = ed.v;
        int w = ed.w;
        if(v == fa) continue;
        if(p1[u] == v) up[v] = max(up[u],d2[u]+w);
        else up[v] = max(up[u],d1[u])+w;
        dfs_u(v,u);
    }
}
int n;
int getNode(){
    int res = INT_MAX;
    for (int i = 1;i <= n;i++){
        res = min(res,max(up[i],d1[i]));
    }
    return res;
    // 最远的最小距离.
}
