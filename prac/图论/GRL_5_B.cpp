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
	vector<int> f1(n), f2(n), from(n, -1), g(n);
	auto dfs1 = [&](auto dfs1, int u, int fa) -> void {
		for(auto [v, w] : e[u]) {
			if(v == fa) continue;
			dfs1(dfs1, v, u);

			if(f1[u] <= f1[v] + w) {
				f2[u] = f1[u];
				f1[u] = f1[v] + w;
				from[u] = v;
			} else if(f2[u] < f1[v] + w) {
				f2[u] = f1[v] + w;
			}
		}
	};
	auto dfs2 = [&](auto dfs2, int u, int fa) -> void {
		for(auto [v, w] : e[u]) {
			if(v == fa) continue;

			if(from[u] == v) {
				g[v] = max(f2[u], g[u]) + w;
			} else {
				g[v] = max(f1[u], g[u]) + w;
			}
			dfs2(dfs2, v, u);
		}
	};
	dfs1(dfs1, 0, -1);
	dfs2(dfs2, 0, -1);
	for(int i = 0; i < n; i++) {
		cout << max(g[i], f1[i]) << '\n';
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