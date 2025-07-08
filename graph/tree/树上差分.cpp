#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int d[N];
/*
 u,v上的路径加x：
 点差分: d[u] += x,d[v] += x,d[lca(u,v)] -= 1,d[fa[lac(u,v)]] -= 1;
 边差分: 把边权下移变成点权 d[u] + x,d[v] + x, d[lac(u,v)] -=2;
*/