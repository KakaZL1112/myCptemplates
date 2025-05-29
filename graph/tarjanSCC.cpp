#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define ll long long

vector<int> e[N];
int dfn[N],low[N],tot = 0;
int instk[N],top = 0;
stack<int> stk;
int scc[N],siz[N],cnt = 0;

//有向图，缩点
void tarjan(int x){
    //入x,盖戳，入栈
    dfn[x] = low[x] = ++tot;
    stk.push(x),instk[x] = 1;
    for (int y:e[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x],low[y]);
        }
        else if(instk[y]){
            low[x] = min(low[x],dfn[y]);
        }
    }
    if(dfn[x] == low[x]){
        int y;++cnt;
        do{
            y = stk.top();
            stk.pop();
            instk[y] = 0;
            scc[y] = cnt;
            ++siz[cnt];
        }while(y != x);
        
    }
}

int cut[N],root;
//割点
void tarjan2(int x){
    dfn[x] = low[x] = ++tot;
    int child = 0;
    for (int y:e[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x],low[y]);
            if(low[y] >= dfn[x]){
                child++;
                if(x != root || child > 1) cut[x] = 1;
            }
        }else{
            low[x] = min(low[x],dfn[y]);
        }
    }

}
//割边
struct edge{int u,v;};
vector<edge> eg;//边集
vector<int> h[N]; //出边
struct brige{int x,y;} bri[N];
ll cntb = 0;
void add(int a,int b){
    eg.push_back({a,b});
    h[a].push_back(eg.size()-1);
}
void tarjan3(int x,int in_edge){
    dfn[x] = low[x] = ++tot;
    for (int i = 0;i < h[x].size();i++){
        int j = h[x][i],y = eg[j].v;
        if(!dfn[y]){
            tarjan3(y,j);
            low[x] = min(low[x],low[y]);
            if(low[y] > dfn[x]){
                bri[++cntb] = {x,y};
            }
        }
        else if(j != (in_edge^1)) low[x] = min(low[x],dfn[y]); //不是反边
    }
} 
int main(){
    
}
