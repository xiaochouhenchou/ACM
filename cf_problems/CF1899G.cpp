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

/*
	二维数点： 计算满足 l <= i <= r, dfn[x] <= dfn[p[i]] <= out[x] 的点是否
			为 0
*/

int n, q, timestmp, idx;
int p[N], dfn[N], out[N], root[N];
vector<int> e[N];
struct node {
	int l, r, cnt;
}tr[N * 4 + 17 * N];

void init() {
	for(int i = 1; i <= idx; i++) {
		tr[i].l = tr[i].r = tr[i].cnt = 0;
	}
	timestmp = idx = 0;
	for(int i = 1; i <= n; i++) {
		e[i].clear();
		dfn[i] = out[i] = 0;
	}
}

void dfs(int u, int fa) {
	dfn[u] = ++timestmp;
	for(int v : e[u]) {
		if(v == fa) continue;
		dfs(v, u);
	}
	out[u] = timestmp;
}

void pushup(int u) {
	tr[u].cnt = tr[tr[u].l].cnt + tr[tr[u].r].cnt;
}

int insert(int p, int l, int r, int v) {
	int q = ++idx;
	tr[q] = tr[p];
	if(l == r) {
		tr[q].cnt += 1;
		return q;
	}
	int mid = (l + r) / 2;
	if(v <= mid) tr[q].l = insert(tr[p].l, l, mid, v);
	else tr[q].r = insert(tr[p].r, mid + 1, r, v);
	pushup(q);
	return q;
}

int query(int u, int l, int r, int L, int R) {
	if(L <= l && r <= R) return tr[u].cnt;
	int mid = (l + r) / 2, res = 0;
	if(L <= mid) res += query(tr[u].l, l, mid, L, R);
	if(R > mid) res += query(tr[u].r, mid + 1, r, L, R);
	return res;
}

void solve() {
	cin >> n >> q;
	init();
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++) {
		root[i] = insert(root[i - 1], 1, n, dfn[p[i]]);
	}
	while(q--) {
		int l, r, x;
		cin >> l >> r >> x;
		int cnt = query(root[r], 1, n, dfn[x], out[x]) - 
			query(root[l - 1], 1, n, dfn[x], out[x]);
		// cout << cnt << '\n';
		cout << (cnt > 0 ? "YES\n" : "NO\n");
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}