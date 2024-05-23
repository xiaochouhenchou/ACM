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
	vector<vector<int>> f(n + 1, vector<int>(2));
	vector<int> s(n + 1);
	auto dfs = [&](auto dfs, int u, int fa) -> void {
		s[u] = 1;
		int sum = 0;
		for(int v : e[u]) {
			if(v == fa) continue;
			dfs(dfs, v, u);
			s[u] += s[v];
			sum += f[v][0];
		}

		f[u][1] = s[u] - 1;
		f[u][0] = sum;
		for(int v : e[u]) {
			if(v == fa) continue;
			f[u][0] = max(f[u][0], sum - f[v][0] + f[v][1]);
		}
	};
	dfs(dfs, 1, 0);
	cout << f[1][0] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}