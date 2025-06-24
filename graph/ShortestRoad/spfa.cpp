#include <bits/stdc++.h>
using namespace std;

int n;
struct edge
{
    int v,w;
};
vector<edge> e[100005];
int dis[100005];
bool vis[100005];
int cnt[100005];
bool spfa(int s){
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    cnt[s]++;
    while(q.size()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto ed : e[u]){
            int v = ed.v;
            int w = ed.w;
            if(dis[u]+w < dis[v]){
                dis[v] = dis[u] + w;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                    cnt[v]++;
                    if(cnt[v] == n + 1){
                        //入队超过n次表示有负环
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}