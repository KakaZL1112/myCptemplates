#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
const int N = 2e6+5;
//---------------------------------------//

int fa[N];
int rk[N];

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
        rk[i] = 1;
    }
}

void u_join(int a,int b)
{
    int x = find(a);
    int y = find(b);
    if (x == y) return;
    if (rk[x] > rk[y]) fa[y] = x;
    else{
        if (rk[x] == rk[y]) rk[y]++;
        fa[x] = y;
    }
}  // 按秩合并

bool isSame(int x, int y){
    return find(x) == find(y);
}


//---------------------------------------//
void solve()
{
}
signed main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int    iloveubutimafridicant = 1;//cin>>iloveubutimafridicant;
    while (iloveubutimafridicant--) solve();
    return 0;
}