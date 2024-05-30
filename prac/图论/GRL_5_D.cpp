#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 100010;

int n, fa[N], top[N], id[N];
int SZ[N], son[N], timestmp;
vector<int> e[N];
struct node {
	ll v;
}tr[N * 4];

void dfs1(int u, int father) {
	fa[u] = father;
	SZ[u] = 1;
	for(int v : e[u]) {
		if(v == father) continue;
		dfs1(v, u);

		SZ[u] += SZ[v];
		if(SZ[son[u]] < SZ[v]) son[u] = v;
	}
}

void dfs2(int u, int t) {
	id[u] = ++timestmp;
	top[u] = t;
	if(!son[u]) return;
	dfs2(son[u], t);
	for(int v : e[u]) {
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}

void pushup(int u) {
	tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
}

void update(int u, int l, int r, int L, int R, ll v) {
	if(L <= l && r <= R) {
		tr[u].v += v;
		return;
	}
	int mid = (l + r) / 2;
	if(L <= mid) update(u << 1, l, mid, L, R, v);
	if(R > mid) update(u << 1 | 1, mid + 1, r, L, R, v);
	pushup(u);
}

ll query(int u, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return tr[u].v;
	}
	int mid = (l + r) / 2;
	ll res = 0;
	if(L <= mid) res += query(u << 1, l, mid, L, R);
	if(R > mid) res += query(u << 1 | 1, mid + 1, r, L, R);
	return res;
}

void update_path(int u, int v, ll w) {
	while(top[u] != top[v]) {
		if(id[top[u]] < id[top[v]]) swap(u, v);
		update(1, 1, n, id[top[u]], id[u], w);
		u = fa[top[u]];
	}
	if(id[u] < id[v]) swap(u, v);
	update(1, 1, n, id[v] + 1, id[u], w);
}

ll query_path(int u, int v) {
	ll res = 0;
	while(top[u] != top[v]) {
		if(id[top[u]] < id[top[v]]) swap(u, v);
		res += query(1, 1, n, id[top[u]], id[u]);
		u = fa[top[u]];
	}
	if(id[u] < id[v]) swap(u, v);
	res += query(1, 1, n, id[v] + 1, id[u]);
	return res;
}

void solve() {
	cin >> n;
	for(int i = 1, k, j; i <= n; i++) {
		cin >> k;
		while(k--) {
			cin >> j;
			j += 1;
			e[i].push_back(j);
			e[j].push_back(i);
		}
	}
	dfs1(1, 0);
	dfs2(1, 1);

	int q;
	cin >> q;
	while(q--) {
		int op;
		cin >> op;
		if(!op) {
			int v, w;
			cin >> v >> w;
			v += 1;
			update_path(fa[v], v, w);
		} else {
			int u;
			cin >> u;
			u += 1;
			cout << query_path(1, u) << '\n';
		}
	}
	// cout << query(1, 1, 6, 6, 6)
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}