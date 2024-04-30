#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const double eps = 1e-8;
const int mod = 1e9 + 9;
const int N = 200010, M = 19;

int n, k;
int a[N], dep[N], f[N][M];
LL d[N];
vector<int> e[N];

void dfs1(int u, int fa) {
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for(int i = M - 1; i >= 1; i--) {
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for(int v : e[u]) {
		if(v == fa) continue;
		dfs1(v, u);
	}
}

// 找离 u 的距离为 k + 1 的祖先
int get_ans(int u) {
	if(dep[u] < k + 1) return 0;

	int x = k + 1;
	for(int i = M - 1; i >= 0; i--) {
		if(x >= (1 << i)) {
			x -= 1 << i;
			u = f[u][i];
		}
	}
	return u;
}

void dfs2(int u, int fa) {
	int ans = get_ans(u);
	d[u] += a[u], d[ans] -= a[u];
	// cout << u << ' ' << ans << '\n';
	for(int v : e[u]) {
		if(v == fa) continue;
		dfs2(v, u);
	}
}

void dfs3(int u, int fa) {
	for(int v : e[u]) {
		if(v == fa) continue;
		dfs3(v, u);
		d[u] += d[v];
	}
}

void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	dfs3(1, 0);
	for(int i = 1; i <= n; i++) {
		cout << d[i] << " \n"[i == n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;	
	while(t--) {
		solve();
	}
	return 0;
}
