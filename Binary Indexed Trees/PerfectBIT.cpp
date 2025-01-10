#include <bits/stdc++.h>
#define int long long
#define endl '\n'
const int N = 5e5+5;
using namespace std;

int n,c[N];
int c2[N];
int d[N];

int lowbit(int i){
    return (-i)&i;
}


//利用差分数组c可得 pre[a[i]] =n*pre[c[i]]-pre[b[i]*(i-1)];

void modify(int x,int z){ //修改单点值
    int t = x;
    for (int i = x;i <= n;i+=lowbit(i)){
        c[i]+=z;
        c2[i]+=z*(t-1); //维护
    }
}

int query(int x){
    int s = 0;
    for (int i = x;i > 0;i-=lowbit(i)){
        s+=c[i];
    }
    return s;
}

int querySum(int x){ //差分数组时，查询前缀和 //区间修改，区间查询
    int s = 0;
    for (int i = x;i >= 1;i-=lowbit(i)){
        s += c[i]*x-c2[i];
    }
    return s;
}


void solve()
{
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        modify(i,a[i]-a[i-1]);
    }
    int m; cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        int x; cin >> x;
        modify(l,x);
        modify(r+1,-x);
    }
    int q;cin >> q;
    while(q--){
        int x;cin >> x;
        cout << querySum(x) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int iloveubuttt = 1;//cin>>iloveubuttt;
    while (iloveubuttt--) solve();
    return 0;
}