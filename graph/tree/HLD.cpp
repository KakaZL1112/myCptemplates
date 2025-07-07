#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> e[N];

#define lc u<<1
#define rc u<<1|1
typedef long long ll;
struct tree{
    int l,r;
    long long add,sum;
}tr[N*4];

int fa[N],dep[N],son[N],siz[N];

int w[N];
int top[N];// top[u] u所在的重链的顶点
int id[N]; // id[u] u在剖分后的新编号
int nw[N]; //新编号在树中对应结点的权值
int cnt = 0;

void dfs1(int u,int father){
    fa[u] = father,dep[u] = dep[father]+1,siz[u] = 1;
    for (int v : e[u]){
        if(v == father) continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if(siz[son[u]] < siz[v]) son[u] = v;
    }
}//init

void dfs2(int u,int t){
    top[u] = t,id[u] = ++cnt,nw[cnt] = w[u];
    if(!son[u]) return;
    dfs2(son[u],t);
    for (int v : e[u]){
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v,v); // 搜轻儿子
    }
}

void pushup(int u){
    tr[u].sum=tr[lc].sum+tr[rc].sum;
}
void pushdown(int u){
    if(tr[u].add){
        tr[lc].sum+=tr[u].add*(tr[lc].r-tr[lc].l+1);
        tr[rc].sum+=tr[u].add*(tr[rc].r-tr[rc].l+1);
        tr[lc].add+=tr[u].add;
        tr[rc].add+=tr[u].add;
        tr[u].add=0;
    }
}
void build(int u,int l,int r){ //构建线段树
    tr[u]={l,r,0,nw[r]};
    if(l==r) return;
    int mid=l+r>>1;
    build(lc,l,mid),build(rc,mid+1,r);
    pushup(u);
}
void change(int u,int l,int r,int k){ //线段树修改
    if(l<=tr[u].l&&tr[u].r<=r){
        tr[u].add+=k;
        tr[u].sum+=k*(tr[u].r-tr[u].l+1);
        return;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(l<=mid) change(lc,l,r,k);
    if(r>mid) change(rc,l,r,k);
    pushup(u);
}
void change_path(int u,int v,int k){ //修改路径
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        change(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    change(1,id[v],id[u],k); //最后一段
}
void change_tree(int u,int k){ //修改子树
    change(1,id[u],id[u]+siz[u]-1,k);
}ll query(int u,int l,int r){ //线段树查询
    if(l<=tr[u].l&&tr[u].r<=r)return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
ll res=0;
    if(l<=mid) res+=query(lc,l,r);
    if(r>mid) res+=query(rc,l,r);
    return res;
}ll query_path(int u,int v){ //查询路径上的权值和 //m * logn^2
ll res=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res+=query(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    res+=query(1,id[v],id[u]); //最后一段
    return res;
}ll query_tree(int u){ //查询子树
    return query(1,id[u],id[u]+siz[u]-1);
}