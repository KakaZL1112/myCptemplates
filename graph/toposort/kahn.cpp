#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5+5;

int n;
vector<int> e[N],tp;
int din[N];
queue<int> q;

bool toposort(){
    for (int i = 1;i <= n;i++){
        if(din[i] == 0) q.push(i);
        while(q.size()){
            int x = q.front();q.pop();
            tp.push_back(x);
            for (auto y:e[x]){
                if(--din[y] == 0) q.push(y);
            }
        }
    }
    if(tp.size() == n) return true;
    else return false;
}

void solve()
{
    int m;
    cin>>n>>m;
    for (int i = 0;i < m;i++){
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        din[b]++;
    }
    if(!toposort()) puts("-1");
    else puts("1");
    cout << q.size() << endl;
    while(q.size()){
        cout << q.front() << endl;
        q.pop();
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int iloveubuttt = 1;//cin>>iloveubuttt;
    while (iloveubuttt--) solve();
    return 0;
}