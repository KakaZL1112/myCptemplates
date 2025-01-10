#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
#define INF 2147483647
#define endl '\n' 
const int mod = 1e9+7;


bool isPrime[100000010];
int Prime[6000010],pcnt = 0;
void getprime(int n)
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2;i <= n;i++)
    {
        if(isPrime[i])
        Prime[++pcnt] = i;
        for (int j = 1;j <= pcnt && i*Prime[j] <= n;j++)
        {
            isPrime[i*Prime[j]] = 0;
            if (i%Prime[j] == 0) break;
        }
    }
}

ll inv[maxn], fac[maxn];  //分别表示逆元和阶乘
//快速幂
ll qPow(ll a,ll b,ll mod){
    ll ans=1;
    while(b){
        if(b&1)
            ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}

void init(){
    //求阶乘
    fac[0]=1;
    for(int i=1;i<maxn;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    //求逆元
    inv[maxn-1]=qPow(fac[maxn-1],mod-2,mod);
    for(int i=maxn-2;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
ll C(int n,int m){
    if(m>n){
        return 0;
    }
    if(m==0)
        return 1;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

// (a/b)%p = (a%p*inv(b))%p
ll getInv(int a,int Mod){
    return qPow(a,Mod-2,Mod);
}


void solve(){
    
}

signed main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int irlyloveyoubutimsofuckingafrid = 1;cin>>irlyloveyoubutimsofuckingafrid;
    while(irlyloveyoubutimsofuckingafrid--) solve();
    return 0;
}