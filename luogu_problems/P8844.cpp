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

int n, m, idx, timestmp, st[N];
int root[N], dfn[N], out[N], dep[N];
vector<int> e[N];
struct node {
	int l, r, cnt;
}tr[N * 4 + 17 * N];

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

int query(int p, int q, int l, int r, int L, int R) {
	if(L <= l && r <= R) return tr[q].cnt - tr[p].cnt;
	int mid = (l + r) / 2;
	int res = 0;
	if(L <= mid) res += query(tr[p].l, tr[q].l, l, mid, L, R);
	if(R > mid) res += query(tr[p].r, tr[q].r, mid + 1, r, L, R);
	return res;
}

void dfs(int u, int fa) {
	dfn[u] = ++timestmp;
	dep[u] = dep[fa] + 1;
	for(int v : e[u]) {
		if(v == fa) continue;
		dfs(v, u);
	}
	out[u] = timestmp;
}

/*
	二维数点问题：将节点按照深度排序，每次询问的是深度 dep[u] >= x，
	dfn[x] <= dfn[u] <= out[x] 的 u 的数量。
*/
void solve() {
	cin >> n >> m;
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	vector<PII> v, op;
	for(int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		op.emplace_back(x, y);
	}
	dfs(1, 0);
	
	v.emplace_back(0, 0);
	for(int i = 1; i <= n; i++) {
		v.emplace_back(dep[i], i);
	}
	sort(v.begin() + 1, v.end());
	for(int i = 1; i <= n; i++) {
		auto [depth, x] = v[i];
		root[i] = insert(root[i - 1], 1, n, dfn[x]);
		if(!st[depth]) {
			st[depth] = i;
		}
	}
	for(int i = 0; i < m; ) {
		if(op[i].x == 2) {
			cout << 0 << '\n';
			i += 1;
			continue;
		}

		auto [t, d] = op[i];
		int j = i + 1;
		while(j < m && op[j].x == 2) {
			j += 1;
		}
		for(int k = i + 1; k < j; k++) {
			if(!st[d]) {
				cout << 0 << '\n';
			} else {
				int u = op[k].y;
				cout << query(root[st[d] - 1], root[n], 1, n, 
					dfn[u], out[u]) << '\n';
			}
		}
		i = j;
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