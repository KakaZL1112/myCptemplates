#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,a[maxn],c[maxn],d[maxn],c2[maxn];

int lowbit(int i){ // c[i]的长度
    return (-i)&i;
}

void add(int i,int z){// 点更新
    int t=i;
    for(;i <= n;i+=lowbit(i)){
        c[i]+=z;
        c2[i]+=z*(t-1);
    }
}
int sum(int i){
    int s=0;
    for(;i>0;i-=lowbit(i)){
        s+=c[i];
    }
    return s;
}

int sumq(int i,int j){
    return sum(j)-sum(i-1);
}

int ask(int i){
    int ans = 0;
    for(;i;i-=lowbit(i)) ans+=c[i];
    return ans;
}

int asksum(int x){
    int ans = 0,t=x;
    for(int i = x;i >= 1;i -=lowbit(i)){
        ans+=c[i]*t-c2[i];
    }
    return ans;
}

void solve()
{
    int m;
    cin>>n>>m;
    memset(c,0,sizeof(c));
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        d[i] = a[i]-a[i-1];
        add(i,d[i]);
    }
    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int x,y,z;
            cin>>x>>y>>z;
            add(x,z);
            add(y+1,-z);
        }
        if(op == 2){
            int x,y;
            cin>>x>>y;
            cout<<asksum(y)-asksum(x-1)<<endl;
        }
    }
}
signed main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int iloveubutimafridicant = 1;
    //cin>>iloveubutimafridicant;
    while(iloveubutimafridicant--) solve();
    return 0;
}