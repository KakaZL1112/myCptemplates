#include <bits/stdc++.h>

using namespace std;

const int N = 500;
int n;
//d as INF
int d[N][N],p[N][N];
void floyd(){
    for (int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++)
                if(d[i][j] > d[i][k]+d[k][j]){
                    d[i][j] = d[i][k]+d[k][j];
                    p[i][j] = k;
                }
        }
    }
}

void path(int i,int j){
    if(p[i][j] == 0) return;
    int k = p[i][j];
    cout << k <<" ";
    path(k,j);
}