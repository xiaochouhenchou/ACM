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
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	vector<int> dep(n + 1), leaf(n + 1), cnt(n + 1), parity(2);
	int minv = 3, maxv = n - 1;
	auto dfs = [&](auto dfs, int u, int fa) -> void {
		int ok = 0;
		for(int v : e[u]) {
			if(v == fa) continue;
			ok = 1;
			dep[v] = dep[u] + 1;
			dfs(dfs, v, u);
			cnt[u] += leaf[v];
		}
		if(!ok) {
			leaf[u] = 1;
			parity[dep[u] & 1] |= 1;
		} else {
			maxv -= max(cnt[u] - 1, 0);
		}
	};
	for(int i = 1; i <= n; i++) {
		if(sz(e[i]) != 1) {
			dfs(dfs, i, 0);
			break;
		}
	}
	if(!parity[0] || !parity[1]) minv = 1;
	cout << minv << ' ' << maxv << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}