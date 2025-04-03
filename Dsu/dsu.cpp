#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Dsu{
private:
    unordered_map<T,T> fa;
    unordered_map<T,int> rk;
public:

    void init(T x){
        fa[x] = x;
        rk[x] = 1;
    }

    T find(T x){
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void merge(T x,T y){
        T xx = find(x);
        T yy = find(y);
        if (xx != yy) {
            if (rk[xx] < rk[yy]) {
                fa[xx] = yy;
            } else if (rk[xx] > rk[yy]) {
                fa[yy] = xx;
            } else {
                fa[xx] = yy;
                rk[yy]++;
            }
        }
    }

    bool isSame(T x , T y){
        return find(x) == find(y);
    }
};