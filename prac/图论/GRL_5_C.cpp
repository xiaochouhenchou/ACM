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
	vector<vector<int>> e(n + 1);
	for(int i = 1, k, j; i <= n; i++) {
		cin >> k;
		while(k--) {
			cin >> j;
			e[i].push_back(j + 1);
		}
	}
	vector<vector<int>> f(n + 1, vector<int>(18));
	vector<int> dis(n + 1);
	auto dfs = [&](auto dfs, int u, int fa) -> void {
		f[u][0] = fa;
		dis[u] = dis[fa] + 1;
		for(int i = 1; i < 18; i++) {
			f[u][i] = f[f[u][i - 1]][i - 1];
		}
		for(int v : e[u]) {
			dfs(dfs, v, u);
		}
	};
	dfs(dfs, 1, 0);
	auto lca = [&](int u, int v) {
		if(dis[u] < dis[v]) swap(u, v);
		for(int i = 17; i >= 0; i--) {
			if(dis[f[u][i]] >= dis[v]) {
				u = f[u][i];
			}
		}
		if(u == v) return u;
		for(int i = 17; i >= 0; i--) {
			if(f[u][i] != f[v][i]) {
				u = f[u][i];
				v = f[v][i];
			}
		}
		return f[u][0];
	};
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u + 1, v + 1) - 1 << '\n';
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