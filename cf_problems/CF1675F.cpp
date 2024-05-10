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
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	vector<int> vis(n + 1), fa(n + 1), dg(n + 1);
	vector<int> dep(n + 1), is_leaf(n + 1, 1);
	vector<vector<int>> e(n + 1);
	vis[x] = vis[y] = 1;
	for(int i = 1, a; i <= k; i++) {
		cin >> a;
		vis[a] = 1;
	}
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		dg[v] += 1;
		dg[u] += 1;
	}
	auto dfs = [&](auto dfs, int u, int father, int depth) -> void {
		dep[u] = depth;
		fa[u] = father;
		is_leaf[father] = 0;
		for(int v : e[u]) {
			if(v == father) continue;
			dfs(dfs, v, u, depth + 1);
		}
	};
	dfs(dfs, x, 0, 0);

	int m = n;
	{
		queue<int> q;
		for(int i = 1; i <= n; i++) {
			if(is_leaf[i] && !vis[i]) {
				q.push(i);
			}
		}
		while(sz(q)) {
			int u = q.front();
			m -= 1;
			q.pop();

			if(fa[u] && !vis[fa[u]]) {
				if(--dg[fa[u]] == 1) {
					q.push(fa[u]);
				}
			}
		}
	}
	cout << (m - 1) * 2 - dep[y] << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}