#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n, t;
	cin >> n >> t;
	vector<vector<int>> e(n + 1);
	vector<int> dis1(n + 1), f(n + 1), dis2(n + 1);
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans = -inf;
	auto dfs1 = [&](auto dfs1, int u, int fa, int d, vector<int> &dis) -> void {
		dis[u] = d;
		f[u] = fa;
		for(int v : e[u]) {
			if(v == fa) continue;
			dfs1(dfs1, v, u, d + 1, dis);
		}
	};
	auto dfs2 = [&](auto dfs2, int u, int fa, int d) -> void {
		dis1[u] = d;
		if(dis1[u] >= dis2[u]) {	// 在这个点肯定会被追上
			return;
		}
		ans = max(ans, dis2[u]);
		for(int v : e[u]) {
			if(v == fa) continue;
			dfs2(dfs2, v, u, d + 1);
		}
	};
	dfs1(dfs1, 1, 0, 0, dis1);

	if(t >= dis1[n]) {
		cout << 0 << '\n';
		return;
	}
	
	int u = n;
	while(dis1[u] != t) {	// 找到从 1 出发走了 t 秒的点，树上两点路径是唯一的，因此这个点也是唯一的 
		u = f[u];
	}

	dfs1(dfs1, n, 0, 0, dis2);	// 从 n 出发计算它到每个点的距离
	// n 出发的点速度是 2，因此到达每个点的距离为 (d + 1) / 2 （即除 2 上取整）
	for(int i = 1; i <= n; i++) {	
		dis2[i] = (dis2[i] + 1) / 2;
	}	
	dfs2(dfs2, u, 0, 0);	// 从 u 出发计算距离
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
