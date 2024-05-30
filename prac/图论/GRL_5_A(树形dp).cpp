#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<vector<PII>> e(n);
	for(int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v >> w;
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	}
	int ans = -inf;
	auto dfs = [&](auto dfs, int u, int fa) -> int {
		int d1 = 0, d2 = 0;
		for(auto [v, w] : e[u]) {
			if(v == fa) continue;

			int t = dfs(dfs, v, u) + w;
			if(t >= d1) {
				d2 = d1, d1 = t;
			} else if(t > d2) {
				d2 = t;
			}
		}
		ans = max(ans, d1 + d2);
		return d1;
	};
	dfs(dfs, 0, -1);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}