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
	结论题：答案为 所有边权的和 * 2 - 树的直径的长度，证明见官方题解。
	求树的直径长度且边权大于等于 0 时可以两次 dfs 求。
*/

void solve() {
	int n;
	cin >> n;
	vector<vector<PII>> e(n + 1);
	ll sumw = 0;
	for(int i = 1, a, b, c; i < n; i++) {
		cin >> a >> b >> c;
		e[a].emplace_back(b, c);
		e[b].emplace_back(a, c);
		sumw += c;
	}
	vector<ll> dis(n + 1);
	auto dfs = [&](auto dfs, int u, int fa) -> void{
		for(auto [v, w] : e[u]) {
			if(v == fa) continue;
			dis[v] = dis[u] + w;
			dfs(dfs, v, u);
		}
	};

	int v = 1;
	dfs(dfs, v, 0);
	for(int i = 1; i <= n; i++) {
		if(dis[i] > dis[v]) {
			v = i;
		}
	}

	dis[v] = 0;
	dfs(dfs, v, 0);
	for(int i = 1; i <= n; i++) {
		if(dis[i] > dis[v]) {
			v = i;
		}
	}

	cout << sumw * 2 - dis[v] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}