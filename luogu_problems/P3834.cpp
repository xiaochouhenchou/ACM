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

int n, m, idx, a[N], b[N], root[N];
struct node {
	int l, r, cnt;
}tr[N * 4 + 18 * N];

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
	tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
	return q;
}

int query(int p, int q, int l, int r, int k) {
	if(l == r) return r;
	int mid = (l + r) / 2;
	int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
	if(cnt >= k) return query(tr[p].l, tr[q].l, l, mid, k);
	return query(tr[p].r, tr[q].r, mid + 1, r, k - cnt);
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + 1 + n);
	int t = unique(b + 1, b + 1 + n) - b - 1;
	for(int i = 1; i <= n; i++) {
		a[i] = lower_bound(b + 1, b + 1 + t, a[i]) - b;
		root[i] = insert(root[i - 1], 1, t, a[i]);
	}
	while(m--) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << b[query(root[l - 1], root[r], 1, t, k)] << '\n';
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