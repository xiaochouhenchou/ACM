#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 200010;
const int mod = 998244353;

ll n, q, a[N], b[N];
struct node {
	ll sumA, sumB, sumAB;
	ll addA, addB, len;
}tr[N * 4];

void pushup(int u) {
	tr[u].sumA = (tr[u << 1].sumA + tr[u << 1 | 1].sumA) % mod;
	tr[u].sumB = (tr[u << 1].sumB + tr[u << 1 | 1].sumB) % mod;
	tr[u].sumAB = (tr[u << 1].sumAB + tr[u << 1 | 1].sumAB) % mod;
}

void build(int u, int l, int r) {
	tr[u] = {
		a[r], b[r], 1ll * a[r] * b[r] % mod, 
		0, 0, r - l + 1		
	};
	if(l == r) return;
	int mid = (l + r) / 2;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void change(node &no, ll x, ll y) {
	no.sumAB = (no.sumAB + no.sumA * y % mod + 
		no.sumB * x % mod + x * y % mod * no.len % mod) % mod;
	no.sumA = (no.sumA + no.len * x % mod) % mod;
	no.sumB = (no.sumB + no.len * y % mod) % mod;
	no.addA = (no.addA + x) % mod;
	no.addB = (no.addB + y) % mod;
}

void pushdown(int u) {
	node &root = tr[u], &le = tr[u << 1], &ri = tr[u << 1 | 1];
	change(le, root.addA, root.addB);
	change(ri, root.addA, root.addB);
	root.addA = root.addB = 0;
}

void update(int u, int l, int r, int L, int R, ll x, ll y) {
	if(L <= l && r <= R) {
		change(tr[u], x, y);
		return;
	}
	pushdown(u);
	int mid = (l + r) / 2;
	if(L <= mid) update(u << 1, l, mid, L, R, x, y);
	if(R > mid) update(u << 1 | 1, mid + 1, r, L, R, x, y);
	pushup(u);
}

ll query(int u, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return tr[u].sumAB;
	}
	pushdown(u);
	ll res = 0, mid = (l + r) / 2;
	if(L <= mid) res = (res + query(u << 1, l, mid, L, R)) % mod;
	if(R > mid) res = (res + query(u << 1 | 1, mid + 1, r, L, R)) % mod;
	return res;
}

void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	build(1, 1, n);

	while(q--) {
		int op, l, r, x;
		cin >> op >> l >> r;
		if(op == 1) {
			cin >> x;
			update(1, 1, n, l, r, x, 0);
		} else if(op == 2) {
			cin >> x;
			update(1, 1, n, l, r, 0, x);
		} else {
			cout << query(1, 1, n, l, r) << '\n';
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