#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define ll long long

vector<int> e[N];
vector<pair<int,int>> query[N];
int fa[N],vis[N],ans[N];

int find(int u){
    if(u == fa[u]) return u;
    return fa[u] = find(fa[u]);
}

void tarjan(int u){
    vis[u] = 1;
    for (auto v : e[u]){
        if(!vis[v]){
            tarjan(v);
            fa[v] = u;
        }
    }
    for (auto q : query[u]){
        int v = q.first,i = q.second;
        if(vis[v]) ans[i] = find(v);
    }
}

int main(){
    return 0;
}
