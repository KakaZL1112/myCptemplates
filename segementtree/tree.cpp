#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define lc u<<1
#define rc u<<1|1

ll w[N];
struct Tree{ //线段树
    ll l,r;
    ll sum;
    ll mul;
    ll maxn;
    ll minn;
    ll add;
}tr[N*4];

void pushup(ll u){ //上传
    tr[u].sum=tr[lc].sum+tr[rc].sum;
    tr[u].maxn = std::max(tr[lc].maxn,tr[rc].maxn);
    tr[u].minn = std::min(tr[lc].minn,tr[rc].minn);
}
void pushdown(ll u){ //下传
    if(tr[u].add){
      tr[lc].sum+=+tr[u].add*(tr[lc].r-tr[lc].l+1),
      tr[rc].sum+=tr[u].add*(tr[rc].r-tr[rc].l+1),
      tr[lc].add+=tr[u].add,
      tr[rc].add+=tr[u].add,
      tr[u].add=0;      
    }
}
void build(ll u,ll l,ll r){ //建树
    tr[u]={l,r,w[l],w[l],w[l],0};
    if(l==r) return;
    ll m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(u);
}
void update(ll u,ll x,ll y,ll k){ //区修
    if(x>tr[u].r || y<tr[u].l) return;
    if(x<=tr[u].l && tr[u].r<=y){
      tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
      tr[u].add+=k;
      return;
    }
    pushdown(u);
    update(lc,x,y,k); 
    update(rc,x,y,k);
    pushup(u);
}

ll query(ll u,ll x,ll y){ //区查
    if(x>tr[u].r || y<tr[u].l) return 0;
    if(x<=tr[u].l && tr[u].r<=y) return tr[u].sum;
    pushdown(u);
    return query(lc,x,y)+query(rc,x,y);
}