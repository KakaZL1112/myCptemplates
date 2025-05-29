#include <bits/stdc++.h>
#define endl '\n'
#define INF 0x7f7f7f7f
const int N = 100005;
using namespace std;

struct edge{
    int v;
    int w;
};
int n,m,s;
vector<edge> e[N];
int d[N],cnt[N],vis[N];
//能处理负边权 ,允许一个点多次入队

queue<int> q;

bool SPFA(int s){
    memset(d,INF,sizeof(d)); d[s] = 0;
    vis[s] = 1;q.push(s);
    while(q.size()){
        int u = q.front();q.pop();vis[u] = 0;
        for (auto ed:e[u]){
            int v = ed.v,w=ed.w;
            if(d[v] > d[u]+w){
                d[v] = d[u]+w;
                cnt[v] = cnt[u]+1;//记录边的数量
                if(cnt[v] >= n) return 1;
                if(!vis[v]) q.push(v),vis[v] = 1;
            }
        }
    }
    return 0;
}


signed main(){
    cin>>n>>m>>s;
    for (int i = 0;i < m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back({b,c});
    }
    SPFA(s);
    for (int i = 1;i <= n;i++) cout<<i<<":"<<d[i]<<" ";
}