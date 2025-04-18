#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
#define INF 2147483647
#define endl '\n' 

vector<int> e[N];

int dep[N],fa[N][20];

void dfs(int u,int father){
    dep[u] = dep[father]+1;
    fa[u][0] = father;
    for(int i = 1;i <= 19;i++){
        fa[u][i] = fa[fa[u][i-1]][i-1];
    }

    for(int v : e[u]){
        if(v != father) dfs(v,u);
    }
}

int lca(int u,int v){
    if(dep[u] < dep[v]) swap(u,v);

    for(int i = 19;i >= 0;i--){
        if(dep[fa[u][i]] >= dep[v]){
            u = fa[u][i];
        }
    }
    if(u == v) return v;

    for(int i = 19;i >= 0;i--){
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i],v = fa[v][i];
        }
    }
    return fa[u][0];
}