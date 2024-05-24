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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> e(n);
	while(m--) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	vector<int> in_stk(n), vis(n);
	auto dfs = [&](auto dfs, int u) -> int {
		in_stk[u] = 1;
		vis[u] = 1;
		for(int v : e[u]) {
			if(!vis[v]) {
				if(dfs(dfs, v)) return 1;
			} else if(in_stk[v]) {
				return 1;
			}
		}
		in_stk[u] = 0;
		return 0;
	};
	int ok = 0;
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			ok |= dfs(dfs, i);
		}
	}
	cout << ok << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}