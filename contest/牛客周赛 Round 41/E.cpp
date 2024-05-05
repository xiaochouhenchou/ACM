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
	int n, l, r;
	string s;
	cin >> n >> l >> r >> s;
	vector<int> a(n), vis(n), f(n);
	vector<set<int>> e(n);
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		u--, v--;
		e[u].emplace(v);
		e[v].emplace(u);
	}

	auto dfs1 = [&](auto dfs1, int u, int fa) -> void {
		f[u] = fa;
		for(int v : e[u]) {
			if(v == fa) continue;
			dfs1(dfs1, v, u);
		}
	};
	dfs1(dfs1, 0, -1);
	for(int i = 0; i < n; i++) {
		if(s[i] == 'R' && ~f[i]) {
			e[f[i]].erase(i);
			e[i].erase(f[i]);
		}
	}

	vector<int> v;
	auto dfs2 = [&](auto dfs2, int u, int fa) -> void {
		v.push_back(u);
		vis[u] = 1;
		for(int v : e[u]) {
			if(v == fa || vis[v]) continue;
			dfs2(dfs2, v, u);
		}
	};

	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			v.clear();
			dfs2(dfs2, i, -1);
			int flag = 0;
			for(int x : v) {
				flag |= s[x] == 'R';
			}
			for(int j = 0; j < sz(v) / 2; j++) {
				a[v[j]] = 1;
			}
			for(int j = sz(v) / 2; j < sz(v) / 2 * 2; j++) {
				a[v[j]] = -1;
			}
			if(sz(v) % 2) a[v[sz(v) - 1]] = flag ? 0 : 1;
		}
	}
	for(int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n - 1];
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