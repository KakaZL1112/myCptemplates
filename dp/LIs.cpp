#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> &a){
    int ans = 0;
    int n = a.size();
    vector<int> b = a;
    int len = 1;
    auto find = [&](int x){
        int L  = 1,R = len;
        while(L <= R){
            int mid = (L+R)/2;
            if(x > b[mid]) L = mid+1;
            else R = mid-1;
        }
        return L;
    };
    for (int i = 2;i <= n;i++){
        if(a[i] > b[len]){
            b[len++] = a[i];
        }else{
            int j = find(a[i]);
            b[j] = a[i];
        }
    }
    return len;
}