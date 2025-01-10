#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ULL;
const int N = 2e5+5;
#define INF 2147483647
#define endl '\n' 

const int P = 131;

//p[i] = P^u,h[i] = s[1~i] 的哈希值
ULL p[N],h[N];

int n;

void init(){
    p[0] = 1,h[0] = 0;
    for(int i = 1;i <= n;i++){
        p[i] = p[i-1]*P;
    }
}

ULL get(int l, int r){
    return h[r]-h[l-1]*p[r-l+1];
}

bool substr(int l1,int r1,int l2,int r2){
    return get(l1,r1) == get(l2,r2);
}


void solve(){
    map<int,int> mp[10005];
    int n;cin>>n;
    int ans = 0;
    for (int i = 1;i <= n;i++){
        string a,b;
        cin>>a>>b;
        int A = a[0]*26 + a[1];
        int B = b[0]*26 + b[1];
        ans += mp[B][A];
        if(A == B) ans-= mp[A][B];
        mp[A][B] ++;
    }
    cout << ans << endl;
}


signed main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int irlyloveyoubutimsofuckingafrid = 1;//cin>>irlyloveyoubutimsofuckingafrid;
    while(irlyloveyoubutimsofuckingafrid--) solve();
    return 0;
}