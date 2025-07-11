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
