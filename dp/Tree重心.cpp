//删除一个点后，剩余各个连通块点数的最大值最小
/*
树的重心如果不唯一，则至多有两个，且这两个重心相邻。
以树的重心为根时，所有子树的大小都不超过整棵树大小的一半。
树中所有点到某个点的距离和中，到重心的距离和是最小的；如果有两个重心，那么到它们的距离和一样。
把两棵树通过一条边相连得到一棵新的树，那么新的树的重心在连接原来两棵树的重心的路径上。
在一棵树上添加或删除一个叶子，那么它的重心最多只移动一条边的距离。
*/
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
vector<int> e[10005];

int del[N],siz[N],mxs,sum,root;//求根
void getroot(int u,int fa){
    siz[u]=1; 
    int s=0;
    for(auto ed:e[u]){
        int v= ed;
        if(v==fa||del[v])continue;
        getroot(v,u);
        siz[u]+=siz[v];
        s=max(s,siz[v]);
    }
    s=max(s,sum-siz[u]);
    if(s<mxs) mxs=s, root=u;
}
