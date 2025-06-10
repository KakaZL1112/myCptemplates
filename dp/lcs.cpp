#include <bits/stdc++.h>
using namespace std;

//最长公共子序列
int f[2005][2005];
int p[2005][2005];
int lcs(string a,string b){
    int m = a.length();
    int n = b.length();
    for (int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(a[i-1] == b[i-1]){
                f[i][j] = f[i-1][j-1]+1;
                p[i][j] = 1;
            }else if(f[i][j-1] > f[i-1][j]){
                f[i][j] = f[i][j-1];
                p[i][j] = 2;
            }else{
                f[i][j] = f[i-1][j];
                p[i][j] = 3;
            }
        }
    }
    int i,j,k;char s[200];
    i = m,j = n;k = f[m][n];
    while(i > 0 && j > 0){
        if(p[i][j] == 1){
            s[k--] = a[i-1];
            i--;j--;
        }else if(p[i][j] == 2) j--;
        else i--;
    }
    for(int i = 1;i <= f[m][n];i++) cout << s[i];
}