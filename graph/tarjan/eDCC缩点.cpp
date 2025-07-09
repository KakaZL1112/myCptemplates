//求边双联通分量 缩完后一定为森林或者树
//树边为原图的割边
//设sum为缩点后叶子节点的个数，最少需要加(sum+1)/2条边，可以让整个图变为边双联通图。
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int M = 1e5+5;

struct edge
{
    int v,ne;
};
int h[N],idx = 1;

int dfn[N],low[N];
stack<int> stk;
int tot;

int dcc[N],cnt;
int bri[M],d[N];
edge e[M];

void add(int a,int b){
    e[++idx].v = b;
    e[idx].ne = h[a];
    h[a] = idx;
}

void tarjan(int x,int ine){
    dfn[x]=low[x]=++tot; 
    stk.push(x);
    for(int i=h[x];i;i=e[i].ne){
        int y=e[i].v;
        if(!dfn[y]){ //若y尚未访问
            tarjan(y,i);
            low[x]=min(low[x],low[y]);
            if(dfn[x]<low[y]){
                bri[i]=bri[i^1]=1;
            } //桥
        }
        else if(i!=(ine^1)) //不是反边
            low[x]=min(low[x],dfn[y]);
    }
    if(dfn[x]==low[x]){
        ++cnt;
        while(1){
            int y=stk.top();stk.pop();
            dcc[y]=cnt; //eDCC
            if(y==x)break;
        }
    }
}
