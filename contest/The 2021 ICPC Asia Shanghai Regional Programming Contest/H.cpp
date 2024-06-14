#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 200010, M = 19;

int n, m, q;
int f[N][M], a[N], w[N], p[N], V[N];
vector<int> g[N];
struct edge {
	int u, v, w;
	bool operator < (const edge &e) const {
		return w < e.w;
	}
}e[N];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void kruskal() {
	sort(e, e + m);
	iota(p + 1, p + 1 + n * 2, 1);
	int idx = n;
	for(int i = 0; i < m; i++) {
		int u = e[i].u, v = e[i].v;
		int pu = find(u), pv = find(v);
		if(pu != pv) {
			int t = ++idx;
			p[pu] = t;
			p[pv] = t;
			w[t] = e[i].w;
			g[pu].push_back(t);
			g[t].push_back(pu);
			g[pv].push_back(t);
			g[t].push_back(pv);
		}
	}
	n = idx;
}

void dfs(int u, int fa) {
	// cout << u << ' ' << fa << ' ' << w[u] << '\n';
	V[u] = a[u];
	f[u][0] = fa;
	for(int i = 1; i < M; i++) {
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for(int v : g[u]) {
		if(v == fa) continue;
		dfs(v, u);
		V[u] += V[v];
	}
}

void solve() {
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	
	kruskal();
	dfs(n, 0);
	w[0] = inf * 2;
	
	while(q--) {
		int x, k;
		cin >> x >> k;

		int ans = k + V[x];
		for(int i = M - 1; i >= 0; ) {
			// cout << ans << ' ' << x << ' ' << i << ' ' << f[x][i] << ' ' << w[f[x][i]] << '\n';
			if(ans >= w[f[x][i]]) {
				ans = k + V[f[x][i]];
				x = f[x][i];
				// cout << x << '\n';
			} else {
				i--;
			}
		}
		cout << ans << '\n';
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