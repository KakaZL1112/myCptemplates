#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
#define INF 2147483647
#define endl '\n' 


struct Point{
    double x,y;
};


Point operator + (Point a,Point b){
    return {a.x+b.x,a.y+b.y};
}

Point operator - (Point a,Point b){
    return {a.x-b.x,a.y-b.y};
}

Point operator * (Point a,double b){
    return {a.x*b,a.y*b};
}


double operator * (Point a,Point b){
    return a.x*b.y-a.y*b.x;
}//叉乘

double operator & (Point a,Point b){
    return a.x*b.x+a.y*b.y;
}//点积


double len(Point a){
    return sqrt(a&a);
}

double angle(Point a,Point b){
    return acos((a&b)/len(a)/len(b));
} // 求角度

double cross(Point a,Point b,Point c){
    return (b-a)*(c-a);
}   
// 叉积 （判断点的位置，逆时针方向为正，顺时针方向为负，共线为0）
//两个叉积的数量积可以判断两条线段是否相交

Point getNode(Point a, Point b, Point u, Point v){
    double t = (a-b)*v/(u*v);
    return a+u*t;
}
//两点式（a,b) u= b-a
void solve(){ 

}


signed main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int irlyloveyoubutimsofuckingafrid = 1;cin>>irlyloveyoubutimsofuckingafrid;
    while(irlyloveyoubutimsofuckingafrid--) solve();
    return 0;
}