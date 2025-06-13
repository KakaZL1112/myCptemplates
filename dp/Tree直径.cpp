#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
struct edge{
    int v,w;
};

vector<edge> e[N];
int vis[N];
int dfs(int u){
    vis[u] = 1;
    int d1 = 0;
    int d2 = 0;
    for (auto ed:e[u]){
        int v = ed.v;
        int w = ed.w;
        if(vis[v]) continue;
        int d = dfs(v)+w;
        if(d >= d1) d2 = d1,d1 = d;
        else if(d > d2) d2 = d;
    }

    int ans = max(ans,d1+d2);

    return ans;
}
