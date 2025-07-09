//不存在割点则为点双联通图
//极大点双联通图为点双联通分量
//割点分裂出去
//将缩点和对应的割点连边 构成树或森林
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> e[N],ne[N];
int dfn[N],low[N],tot;
stack<int> stk;
vector<int> dcc[N];
int cut[N],root,cnt,num,id[N];

void tarjan(int x){
    dfn[x] = low[x] = ++tot;
    stk.push(x);
    if(!e[x].size()){
        dcc[++cnt].push_back(x);
        return;
    }
    int child = 0;
    for (auto y : e[x]){
        tarjan(y);
        low[x] = min(low[x],low[y]);
        if(low[y] >= dfn[x]){
            child++;
            if(x != root || child > 1){
                cut[x] = 1;
            }
            cnt++;
            while(1){
                int z = stk.top();stk.pop();
                dcc[cnt].push_back(z);
                if(z == y) break;
            }
        }else{
            low[x] = min(low[x],low[y]);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    while(m--){
        int a,b;cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (root = 1;root <= n;root++){
        if(!dfn[root]){
            tarjan(root);
        }
    }

    //割点新编号
    num = cnt;

    for (int i = 1;i <= n;i++){
        if(cut[i]) id[i] = ++num;
    }

    //建新图

    for (int i = 1;i <= cnt;i++){
        for (int j = 0;j < dcc[i].size();j++){
            int x = dcc[i][j];
            if(cut[x]){
                ne[i].push_back(id[x]);
                ne[id[x]].push_back(i);
            }
        }
    }
}