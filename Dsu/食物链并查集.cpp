#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
const int N = 2e6+5;
//---------------------------------------//

int fa[N];
int rk[N];
int e[N];


int find(int a)
{
    if (fa[a] == a) return a;
    return fa[a] =  find(fa[a]);
}

void join(int a,int b)
{
    int fx = find(a),fy = find(b);
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

bool isSame(int a, int b){
    return find(a) == find(b);
}


//---------------------------------------//
void solve()
{
    int n,k;
    cin>>n>>k;
    init(3*(n+1));
    int cnt = 0;
    while(k--){
        int op,a,b;
        cin>>op>>a>>b;
        if(a < 1 || a > n || b < 1 || b > n){
            cnt++;continue;
        }
        if(op == 2 && a == b){
            cnt++;continue;
        }
        if(op == 1){
            if(find(a) == find(b+n) || find(b) == find(a+n)) cnt++;
            else{
                join(a,b);
                join(a+n,b+n);
                join(a+2*n,b+2*n);
            }
        }else if(op == 2){
            if(find(a) == find(b)|| find(b) == find(a+n)) cnt++;
            else{
                join(a,b+n);
                join(a+n,b+2*n);
                join(a+2*n,b);
            }
        }
    }
    cout<<cnt<<endl;
}
signed main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int    iloveubutimafridicant = 1;//cin>>iloveubutimafridicant;
    while (iloveubutimafridicant--) solve();
    return 0;
}