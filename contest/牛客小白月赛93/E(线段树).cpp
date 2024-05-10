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

//1 0
int n, m;
string c;
struct node {
	ll cnt_b, cnt_w;
	ll sum_b, sum_w;
	ll v;
}tr[N * 4], e;

void pushup(node &root, node &le, node &ri) {
	ll res = le.cnt_b * ri.sum_w % mod;
	res = (res - le.sum_b * ri.cnt_w % mod) % mod;
	res = (res + mod) % mod;
	res = (res + le.cnt_w * ri.sum_b % mod) % mod;
	res = (res - le.sum_w * ri.cnt_b % mod) % mod;
	res = (res + mod) % mod;
	root.cnt_b = (le.cnt_b + ri.cnt_b) % mod;
	root.cnt_w = (le.cnt_w + ri.cnt_w) % mod;
	root.sum_b = (le.sum_b + ri.sum_b) % mod;
	root.sum_w = (le.sum_w + ri.sum_w) % mod;
	root.v = (le.v + ri.v + res) % mod;
}

void pushup(int u) {
	pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
	tr[u] = {c[r] == '1', c[r] == '0', 
			c[r] == '1' ? r : 0, 
			c[r] == '0' ? r : 0};
	if(l == r) return;
	int mid = (l + r) / 2;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

node query(int u, int l, int r, int L, int R) {
	if(L <= l && r <= R) return tr[u];
	int mid = (l + r) / 2;
	if(R <= mid) return query(u << 1, l, mid, L, R);
	if(L > mid) return query(u << 1 | 1, mid + 1, r, L, R);
	node res = e;
	node le = query(u << 1, l, mid, L, R);
	node ri = query(u << 1 | 1, mid + 1, r, L, R);
	pushup(res, le, ri);
	return res;
}

void solve() {
	cin >> n >> m >> c;
	c = " " + c;
	build(1, 1, n);
	while(m--) {
		int l, r;
		cin >> l >> r;
		cout << query(1, 1, n, l, r).v << '\n';
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