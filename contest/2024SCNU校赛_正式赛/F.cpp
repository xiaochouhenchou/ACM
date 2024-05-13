#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

/*
	思路：矩阵黑白染色，变成国际象棋的棋盘。相邻两个的数一定是
		 颜色不同的，有解的条件就是黑色格子的和等于白色格子的和。
*/

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	ll sum[2] = {0};
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			sum[(i + j) & 1] += a[i][j];
		}
	}
	cout << (sum[0] == sum[1] ? "Yes\n" : "No\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}