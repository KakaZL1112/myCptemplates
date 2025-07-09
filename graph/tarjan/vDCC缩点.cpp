//不存在割点则为点双联通图
//极大点双联通图为点双联通分量
//割点分裂出去
//将缩点和对应的割点连边 构成树或森林
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,m,a,b;
vector<int> e[N],ne[N]; 
int dfn[N],low[N],tot;
stack<int> stk;
bool cut[N];
vector<int> dcc[N];
int root,cnt,num,id[N];

void tarjan(int x){
    dfn[x]=low[x]=++tot;
    stk.push(x);
    if(x==root&&!e[x].size()){//孤立点
        dcc[++cnt].push_back(x);
        return;
    }
    int child=0;  
    for(int y : e[x]){
        if(!dfn[y]){//若y尚未访问
            tarjan(y);////
            low[x]=min(low[x],low[y]); 
            if(low[y]>=dfn[x]){
                child++;
                if(x!=root||child>1){
                    cut[x]=true; 
                }
                
                int z; cnt++;

                do{ //记录vDCC
                    z = stk.top();
                    dcc[cnt].push_back(z);
                }while(z!=y);

                dcc[cnt].push_back(x);
            }
        }
        else low[x]=min(low[x],dfn[y]);
    }
}
int main(){
    cin>>n>>m;
    while(m --){
        cin>>a>>b;
        e[a].push_back(b),
        e[b].push_back(a);
    }
    for(root=1;root<=n;root++){
        if(!dfn[root]){
            tarjan(root);
        }
    }
        
    //给每个割点一个新编号（cnt+1开始）
    num=cnt;
    for(int i=1;i<=n;i++){
        if(cut[i])id[i]=++num;
    }
    //建新图，从每个vDCC向对应割点连边
    for(int i=1;i<=cnt;i++){
        for(int j=0;j<dcc[i].size();j++){
            int x=dcc[i][j];
                if(cut[x]){
                    ne[i].push_back(id[x]),
                    ne[id[x]].push_back(i);        
                }
        }
    }
    return 0;
}