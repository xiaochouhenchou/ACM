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

struct node {
	int v, op;
}tr[N * 4];

void build(int u, int l, int r) {
	tr[u] = {INT_MAX, INT_MAX};
	if(l == r) return;
	int mid = (l + r) / 2;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}

void pushup(int u) {
	tr[u].v = min(tr[u << 1].v, tr[u << 1 | 1].v);
}

void pushdown(int u) {
	if(tr[u].op != INT_MAX) {
		tr[u << 1].v = tr[u].op; tr[u << 1].op = tr[u].op;
		tr[u << 1 | 1].v = tr[u].op; tr[u << 1 | 1].op = tr[u].op;
		tr[u].op = INT_MAX;
	}
}

void update(int u, int l, int r, int L, int R, int v) {
	// cout << l << ' ' << r << ' ' << L << ' ' << R << ' ' << v << '\n';
	if(L <= l && r <= R) {
		tr[u].v = v;
		tr[u].op = v;
		return;
	}
	pushdown(u);
	int mid = (l + r) / 2;
	if(L <= mid) update(u << 1, l, mid, L, R, v);
	if(R > mid) update(u << 1 | 1, mid + 1, r, L, R, v);
	pushup(u);
}

int query(int u, int l, int r, int L, int R) {
	if(L <= l && r <= R) return tr[u].v;
	pushdown(u);
	int mid = (l + r) / 2;
	int res = INT_MAX;
	if(L <= mid) res = min(res, query(u << 1, l, mid, L, R));
	if(R > mid) res = min(res, query(u << 1 | 1, mid + 1, r, L, R));
	return res;
}

void solve() {
	int n, q;
	cin >> n >> q;
	build(1, 0, n - 1);
	while(q--) {
		int op;
		cin >> op;
		if(!op) {
			int s, t, x;
			cin >> s >> t >> x;
			update(1, 0, n - 1, s, t, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(1, 0, n - 1, l, r) << '\n';
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