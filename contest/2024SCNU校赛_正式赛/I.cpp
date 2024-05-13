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
	思路： f[i][j]表示当前位于第 i 个点，已经跳过了 j 个点的最小花费。
		  如果直接从 i - 1 到 i，那么 f[i][j] = f[i - 1][j] + dis(i - 1, i);
		  如果从某个点 k -> i，那么 f[i][j] = f[k][j - (i - k - 1)] + dis(k, i) - 
		  2^(j - (i - k - 1)) + 2^j，其中 i - k - 1 表示 k -> i 跳过的点
*/

void solve() {
	int n;
	cin >> n;
	vector<ll> x(n + 1), y(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	auto dis = [&](int i, int j) {
		double dx = x[i] - x[j];
		double dy = y[i] - y[j];
		return sqrt(dx * dx + dy * dy);
	};
	auto pow2 = [&](int x) {
		return x < 0 ? 0 : (1 << x);
	};
	vector<vector<double>> f(n + 1, vector<double>(31, 1e18));
	f[1][0] = 0.0;
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j <= 30; j++) {
			f[i][j] = f[i - 1][j] + dis(i - 1, i);
			for(int k = 0; k <= j && i - k - 1 >= 1; k++) {
				int idx = i - k - 1;
				f[i][j] = min(f[i][j], f[idx][j - k] + dis(idx, i) - 
							pow2(j - k - 1) + pow2(j - 1));
			}
		}
	}
	double ans = 1e18;
	for(int j = 0; j <= 30; j++) {
		ans = min(ans, f[n][j]);
	}
	cout << fixed << setprecision(3) << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}