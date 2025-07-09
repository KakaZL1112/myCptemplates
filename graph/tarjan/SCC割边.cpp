#include <bits/stdc++.h>
using namespace std;

const int N=210,M=10010;
int n,m,a,b,cnt;
struct edge{int u,v;};
vector<edge>e;
vector<int>h[N];
int dfn[N],low[N],tot;
struct bridge{
    int x,y;
    bool operator<(const bridge &t)const{
        if(x==t.x)return y<t.y;
        return x<t.x;
    }
}bri[M];

void add(int a,int b){
    e.push_back({a,b});
    h[a].push_back(e.size()-1);
}
void tarjan(int x,int in_edge){
    dfn[x]=low[x]=++tot;
    for(int i=0;i<h[x].size();i++){
        int j=h[x][i], y=e[j].v;
        if(!dfn[y]){//若y尚未访问
        tarjan(y,j);
        low[x]=min(low[x],low[y]);
        if(low[y]>dfn[x]){
            bri[cnt++]={x,y};
        }
        }
        else if(j!=(in_edge^1))//不是反边
        low[x]=min(low[x],dfn[y]);
    }
}

int main(){
    cin>>n>>m;
    while(m --){
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    for(int i=1; i<=n; i++)
        if(!dfn[i])tarjan(i,0);

    sort(bri,bri+cnt);  
    for(int i=0;i<cnt;i++)
        printf("%d %d\n",bri[i].x,bri[i].y);
    return 0;
}