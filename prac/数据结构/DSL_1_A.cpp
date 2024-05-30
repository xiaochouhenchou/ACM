#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

struct Union {
	int n;
	vector<int> p;
	Union() {}
	Union(int sz) : n(sz) {
		p.resize(sz);
		iota(p.begin(), p.end(), 0);
	}
	int find(int x) {
		return x == p[x] ? p[x] : p[x] = find(p[x]);
	}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if(x != y) {
			p[x] = y;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

void solve() {
	int n, q;
	cin >> n >> q;
	Union p(n);
	while(q--) {
		int op, x, y;
		cin >> op >> x >> y;
		if(!op) {
			p.merge(x, y);
		} else {
			cout << p.same(x, y) << '\n';
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