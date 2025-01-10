#include <bits/stdc++.h>
const int N = 2e5+5;
using namespace std;

struct edge
{
    int u,v,w;
};


bool cmp(edge a, edge b){
    return a.w < b.w;
}

vector<edge> e;

int  fa[N],ans,cnt;

int find(int x){
    if(fa[x]==x) return x;
    return fa[x] = find(fa[x]);
}
int n,m;
bool kruskal(){
    sort(e.begin(),e.end(),cmp);
    for (int i = 1;i <= n;i++) fa[i] = i;
    for (int i = 0;i < m;i++){
        int x = find(e[i].u);
        int y = find(e[i].v);
        if(x != y){
            fa[x] = y;
            ans += e[i].w;
            cnt++;
        }
    }
    return cnt == n-1;
}

int main(){
    cin>>n>>m;
    for (int i = 1;i <= m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e.push_back({a,b,c});
        e.push_back({b,a,c});
    }
    if(kruskal()){
        cout<<ans<<endl;
    }else{
        cout<<"orz"<<endl;
    }
}
