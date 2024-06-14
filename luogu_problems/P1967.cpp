#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 20010, M = 50010;

int n, m, q, idx, a[N], p[N], vis[N];
int f[N][16], dep[N];
vector<int> tr[N];
struct edge {
	int u, v, w;
	bool operator < (const edge &e) {
		return w > e.w;
	}
}e[M];

int find(int x) {
	return x == p[x] ? p[x] : p[x] = find(p[x]);
}

void dfs(int u, int fa) {
	vis[u] = 1;
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for(int i = 1; i <= 15; i++) {
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for(int v : tr[u]) {
		if(v == fa) continue;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 15; i >= 0; i--) {
		if(dep[f[u][i]] >= dep[v]) {
			u = f[u][i];
		}
	}
	if(u == v) return u;
	for(int i = 15; i >= 0; i--) {
		if(f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	}
	return f[u][0];
}
void solve() {
	int n, m;
	cin >> n >> m;
	idx = n;
	iota(p + 1, p + 1 + n * 2, 1);
	for(int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e, e + m);
	for(int i = 0; i < m; i++) {
		auto [u, v, w] = e[i];
		int pu = find(u);
		int pv = find(v);
		if(pu != pv) {
			int x = ++idx;
			p[pu] = x;
			p[pv] = x;
			tr[x].push_back(pu);
			tr[pu].push_back(x);
			tr[x].push_back(pv);
			tr[pv].push_back(x);
			a[x] = w;
		}
	}
	n = idx;
	for(int i = n; i; i--) {
		if(!vis[i]) dfs(i, 0);
	}
	cin >> q;
	while(q--) {
		int x, y;
		cin >> x >> y;
		if(find(x) != find(y)) cout << -1 << '\n';
		else {
			cout << a[lca(x, y)] << '\n';
		}
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