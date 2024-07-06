#include <bits/stdc++.h> 
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 100010;

int n, m;
int timestmp, dcc_cnt, cnt[N];
int dfn[N], low[N], dcc_id[N], dcc[N];
ll ans;

struct edge {
	int v, id;
	edge() {}	
	edge(int _v, int _id) : v(_v), id(_id) {}
};
vector<edge> e[N];
vector<int> bridge[N], g[N];

void tarjan(int u, int fa = -1) {
	dfn[u] = low[u] = ++timestmp;
	for(int i = 0; i < sz(e[u]); i++) {
		int v = e[u][i].v;
		int id = e[u][i].id;
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(dfn[u] < low[v]) {
				bridge[u][i] = bridge[v][id] = 1;
			}
		} else if(v != fa) {
			low[u] = min(low[u], dfn[v]);
		}
	}	
}

void dfs1(int u) {
	dcc[dcc_cnt] += 1;
	dcc_id[u] = dcc_cnt;
	for(int i = 0; i < sz(e[u]); i++) {
		int v = e[u][i].v;
		if(dcc_id[v] || bridge[u][i]) continue;
		dfs1(v);
	}	
}

void dfs2(int u, int fa = -1) {
	cnt[u] = dcc[u];
	for(int v : g[u]) {
		if(v == fa) continue;
		dfs2(v, u);
		cnt[u] += cnt[v];
	}
	ll res = 1ll * cnt[u] * (cnt[u] - 1) / 2;
	res += 1ll * (n - cnt[u]) * (n - cnt[u] - 1) / 2;
	ans = min(ans, res);
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
			dfs1(i);
		}
	}
	for(int u = 1; u <= n; u++) {
		for(int i = 0; i < sz(e[u]); i++) {
			int v = e[u][i].v;
			if(dcc_id[u] != dcc_id[v]) {
				g[dcc_id[u]].push_back(dcc_id[v]);
			}
		}	
	}
	ans = INF;
	dfs2(1);
	cout << ans << '\n';
	
	for(int i = 1; i <= n; i++) {
		dfn[i] = low[i] = dcc_id[i] = 0;
		e[i].clear();
		bridge[i].clear();
	}
	for(int i = 1; i <= dcc_cnt; i++) {
		g[i].clear();
		dcc[i] = cnt[i] = 0;
	}
	timestmp = dcc_cnt = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}