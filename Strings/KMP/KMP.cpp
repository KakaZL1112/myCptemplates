#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
#define INF 2147483647
#define endl '\n' 


int ne[N];

ne[1] = 0;
string P;
for (int i = 2,j = 0;i <= n;i++){
    while(j && P[i] != P[i+1]) j =ne[j];
    if(P[i] == P[j+1]) j++;
    ne[i] = j;
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