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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> e(n + 1);
	vector<int> dep(n + 1), Size(n + 1);
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	ll ans = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	auto dfs = [&](auto dfs, int u, int fa, int depth) -> void {
		dep[u] = depth;
		Size[u] = 1;
		for(int v : e[u]) {
			if(v == fa) continue;
			dfs(dfs, v, u, depth + 1);
			Size[u] += Size[v];
		}
		int tmp = dep[u] - (Size[u] - 1);
		q.push(tmp);
		ans += tmp;
		while(sz(q) > k) {
			ans -= q.top();
			q.pop();
		}
	};
	dfs(dfs, 1, 0, 0);
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