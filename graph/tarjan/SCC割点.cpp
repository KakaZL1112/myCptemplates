#include <bits/stdc++.h>
using namespace std;

//缩完点后为拓扑图
const int N=20010;
int n,m,a,b;
vector<int> e[N]; 
int dfn[N],low[N],tot;
bool cut[N]; // cut[u] = 1 u点为割点
int root;

void tarjan(int x){
    dfn[x]=low[x]=++tot;
    int child=0;
    for(int y : e[x]){
        if(!dfn[y]){//若y尚未访问
        tarjan(y);
        low[x]=min(low[x],low[y]); 
        if(low[y]>=dfn[x]){
            child++;//子树个数
            if(x!=root||child>1)
            cut[x]=true;
        }
        }
        else//若y已经访问
        low[x]=min(low[x],dfn[y]);
    }
}