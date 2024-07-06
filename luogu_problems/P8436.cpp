#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 500010;

int n, m, dfn[N], low[N];
int dcc_cnt, timestmp, dcc_id[N];
vector<int> dcc[N];
struct edge {
	int v, id;	// 边的终点、反向边的编号
	edge() {}
	edge(int _v, int _id) : v(_v), id(_id) {}
};
vector<edge> e[N];	// e[u]: 以 u 为起点的边的集合
vector<int> bridge[N];	// bridge[u]: 以 u 为起点哪些边为桥

void tarjan(int u, int fa = -1) {
	dfn[u] = low[u] = ++timestmp;
	for(int i = 0; i < sz(e[u]); i++) {
		auto [v, id] = e[u][i];
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]) {
				bridge[u][i] = bridge[v][id] = 1;
			}
		} else if(v != fa) {
			low[u] = min(low[u], dfn[v]);
		}
	}
}

void dfs(int u) {
	dcc_id[u] = dcc_cnt;
	dcc[dcc_cnt].push_back(u);
	for(int i = 0; i < sz(e[u]); i++) {
		auto [v, id] = e[u][i];
		if(dcc_id[v] || bridge[u][i]) continue;
		dfs(v);
	}
}

void solve() {
	cin >> n >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		int x = sz(e[u]), y = sz(e[v]);
		e[u].emplace_back(v, y);
		e[v].emplace_back(u, x);
	}
	for(int i = 1; i <= n; i++) {
		bridge[i].resize(sz(e[i]));
	}
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1; i <= n; i++) {
		if(!dcc_id[i]) {
			dcc_cnt += 1;
			dfs(i);
		}
	}
	cout << dcc_cnt << '\n';
	for(int i = 1; i <= dcc_cnt; i++) {
		cout << sz(dcc[i]);
		for(int x : dcc[i]) {
			cout << " " << x;
		}
		cout << '\n';
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