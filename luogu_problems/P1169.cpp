#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// 思路: 悬线法dp	
// https://blog.csdn.net/mlh12356/article/details/128191624
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	vector<vector<int>> l(n + 1, vector<int>(m + 1));
	vector<vector<int>> r(n + 1, vector<int>(m + 1));
	vector<vector<int>> h(n + 1, vector<int>(m + 1, 1));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			l[i][j] = j;
			if(j - 1 && a[i][j - 1] != a[i][j]) {
				l[i][j] = l[i][j - 1];
			}
		}
		for(int j = m; j; j--) {
			r[i][j] = j;
			if(j + 1 <= m && a[i][j + 1] != a[i][j]) {
				r[i][j] = r[i][j + 1];
			}
		}
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i - 1][j] != a[i][j]) {
				h[i][j] = h[i - 1][j] + 1;
				l[i][j] = max(l[i - 1][j], l[i][j]);
				r[i][j] = min(r[i - 1][j], r[i][j]);
			}
		}
	}
	ll sq = 0, rec = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ll x = h[i][j], y = r[i][j] - l[i][j] + 1;
			rec = max(rec, x * y);
			sq = max(sq, min(x, y) * min(x, y));
		}
	}
	cout << sq << '\n' << rec << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}