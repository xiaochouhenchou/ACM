#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 10010;

int n, m;
int dfn[N], low[N], f[N], timestmp;
int scc_cnt, w[N], W[N], id[N];
bool in_stk[N];
vector<int> e[N], g[N], stk;

void tarjan(int u) {
	dfn[u] = low[u] = ++timestmp;
	stk.push_back(u);
	in_stk[u] = true;
	for(int v : e[u]) {
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(in_stk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]) {
		scc_cnt += 1;
		int cur;
		do {
			cur = stk.back();
			stk.pop_back();
			in_stk[cur] = false;
			W[scc_cnt] += w[cur];
			id[cur] = scc_cnt;
		} while(cur != u);
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	while(m--) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) {
			tarjan(i);
		}
	}
	for(int u = 1; u <= n; u++) {
		for(int v : e[u]) {
			if(id[u] != id[v]) {
				g[id[u]].push_back(id[v]);
			}
		}
	}
	int ans = 0;
	for(int u = scc_cnt; u; u--) {
		f[u] = max(f[u], W[u]);
		ans = max(ans, f[u]);
		for(int v : g[u]) {
			f[v] = max(f[v], f[u] + W[v]);
		}
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