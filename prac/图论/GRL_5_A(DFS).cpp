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
	vector<int> dis(n);
	auto dfs = [&](auto dfs, int u) -> void {
		for(auto [v, w] : e[u]) {
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				dfs(dfs, v);
			}
		}
	};
	fill(dis.begin(), dis.end(), inf);
	dis[0] = 0;
	dfs(dfs, 0);
	int l = -1, maxv = -inf;
	for(int i = 0; i < n; i++) {
		if(maxv < dis[i]) {
			maxv = dis[i];
			l = i;
		}
	}
	fill(dis.begin(), dis.end(), inf);
	dis[l] = 0;
	dfs(dfs, l);
	int ans = -inf;
	for(int i = 0; i < n; i++) {
		 ans = max(ans, dis[i]);
	}
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