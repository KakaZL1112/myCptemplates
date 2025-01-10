#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,a[maxn],c[maxn];

int lowbit(int i){ // c[i]的长度
    return (-i)&i;
}

void modify(int x,int z){// 点更新
    for(int i = x;i <= n;i+=lowbit(i)){
        c[i]+=z;
    }
}

int sum(int x){
    int s=0;
    for(int i = x;i>0;i-=lowbit(i)){
        s+=c[i];
    }
    return s;
}

int sumq(int i,int j){
    return sum(j)-sum(i-1);
}

void solve()
{
    int m;
    cin>>n>>m;
    memset(c,0,sizeof(c));
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        modify(i,a[i]);
    }
    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int x,y;
            cin>>x>>y;
            modify(x,y);
        }
        if(op == 2){
            int x,y;
            cin>>x>>y;
            int res = sumq(x,y);
            cout<<res<<endl;
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