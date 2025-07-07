#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
int fa[N];
int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] =  find(fa[x]);
}
void join(int x,int y)
{
    int fx = find(x),fy = find(y);
    if (fx != fy){
        fa[fx] = fy;
    }
}
void init(int n){
    for (int i = 0;i < n;i++){
        fa[i] = i;
    }
}//并查集部分

struct edge
{
    int u,v,w;
};

int n,m;
edge e[N*2];
int val[N*2]; // 新点的权值
bool cmp(edge a,edge b){return a.w < b.w;}

void Ex_Kruskal(){
    int cnt = n + 1;
    sort(e+1,e+1+m,cmp);
    init(m + n +1);
    for (int i = 1;i <= n;i++){
        int u = e[i].u;
        int v = e[i].v;
        int w = e[i].w;
        if(find(u) != find(v)){
            fa[u] = fa[v] = cnt;
            val[cnt] = w;
            join(cnt,u);join(cnt,v);
            cnt++;
            if(cnt == 2*n-1) break;
        }
    }
}
