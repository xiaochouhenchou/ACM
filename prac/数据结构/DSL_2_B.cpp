#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

struct bitTree {
	int n;
	vector<int> tr;
	bitTree() {}
	bitTree(int sz) : n(sz) {
		tr.resize(sz + 1);
	}
	int lowbit(int x) { return x & -x; }
	void add(int x, int v) {
		while(x <= n) {
			tr[x] += v;
			x += lowbit(x);
		}
	}
	int sum(int x) {
		int res = 0;
		while(x) {
			res += tr[x];
			x -= lowbit(x);
		}
		return res;
	}
};

void solve() {
	int n, q;
	cin >> n >> q;
	bitTree tr(n);
	while(q--) {
		int op, x, y;
		cin >> op >> x >> y;
		if(!op) tr.add(x, y);
		else {
			cout << tr.sum(y) - tr.sum(x - 1) << '\n';
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