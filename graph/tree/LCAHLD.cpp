#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> e[N];

int fa[N],dep[N],son[N],sz[N];

int top[N];// top[u] u所在的重链的顶点

void dfs1(int u,int father){
    fa[u] = father,dep[u] = dep[father]+1,sz[u] = 1;
    for (int v : e[u]){
        if(v == father) continue;
        dfs1(v,u);
        sz[u] += sz[v];
        if(sz[son[u]] < sz[v]) son[u] = v;
    }
}//init

void dfs2(int u,int t){
    top[u] = t;
    if(!son[u]) return;
    dfs2(son[u],t);
    for (int v : e[u]){
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v,v); // 搜轻儿子
    }
}

int lca(int u,int v){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}