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
	只有 a > 1 && b = 1 或者 a = 1 && b > 1 两种可能
	（特判 n = 2 或 3 且 a = b = 1 的情况）
*/
void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	if(min(a, b) > 1 || ((n == 2 || n == 3) && max(a, b) == 1)) {
		cout << "NO\n";
		return;
	}
	vector<vector<int>> ans(n + 1, vector<int>(n + 1));
	if(b == 1) {
		for(int i = 1; i < n - a + 1; i++) {
			ans[i][i + 1] = ans[i + 1][i] = 1;
		}
	} else {
		for(int i = 1; i < n - b + 1; i++) {
			ans[i][i + 1] = ans[i + 1][i] = 1;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				ans[i][j] = !ans[i][j];
				if(i == j) ans[i][j] = 0;
			}
		}
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}