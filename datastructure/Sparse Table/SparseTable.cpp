#include <bits/stdc++.h>
#define int long long
#define endl '\n'
const int MAXN = 5e5+5;
const int MAX_L = 20;
using namespace std;
int stmax[MAXN][MAX_L];
int lg[MAXN];
int n,q;
void solve()
{
    cin >> n >> q;
	lg[1] = 0;
	for (int i = 2;i <= n;i++)lg[i] = lg[i>>1]+1;
    for (int i = 1;i <= n;i++){
        cin>>stmax[i][0];
    }

	for (int j = 1; (1 << j) <= n; j++)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j-1))][j - 1]);
		}
	}
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		int x = lg[r-l+1];
		cout << max(stmax[l][x], stmax[r - (1 << x) + 1][x])<< endl;
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