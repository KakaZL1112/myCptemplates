#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e6+5;
//---------------------------------------//

unordered_map<int,int> fa;
vector<pair<int,int>> vt;
int rk[N];
int e[N];
int dis[N];
int cnt[N];


int find(int a)
{
    if (fa[a] == a) return a;
    int t = find(fa[a]);
    dis[a] += dis[fa[a]];  //更新距离 原距离 + 父节点更新的距离（前面加上元素的距离）
    fa[a] = t;
    return fa[a];
}

void u_join1(int a,int b)
{
    int x = find(a);
    int y = find(b);
    fa[x] = y;
    dis[x] = cnt[y];  //距离 = 前面元素的个数（距离）
    cnt[y] += cnt[x]; //总个数 = 后面的个数+前面的个数
    cnt[x] = cnt[y];  //更新元素个数
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

void u_init(int n){
    for (int i = 0;i < n;i++){
        fa[i] = i;
        rk[i] = 1;
        cnt[i] = 1;
    }
}

bool isSame(int a, int b){
    return find(a) == find(b);
}

void solve()
{
    int n;cin>>n;
    u_init(30010);
    while(n--){
        char op;int a,b;
        cin>>op;cin>>a>>b;
        if(op == 'M'){
            if(find(a) != find(b)) u_join1(a,b);
        }
        if(op == 'C'){
            if(find(a) != find(b)) cout<<"-1"<<endl;
            else cout<<abs(dis[a] - dis[b])-1<<endl;
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int    iloveubutimafridicant = 1;//cin>>iloveubutimafridicant;
    while (iloveubutimafridicant--) solve();
    return 0;
}