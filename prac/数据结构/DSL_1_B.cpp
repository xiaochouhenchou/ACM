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
	vector<int> p, d;	// d[x]: a[x] - a[p[x]]
	Union() {}
	Union(int sz) : n(sz) {
		p.resize(sz);
		d.resize(sz, 0);
		iota(p.begin(), p.end(), 0);
	}
	int find(int x) {
		if(x == p[x]) return p[x];

		int f = find(p[x]);
		d[x] += d[p[x]];
		return p[x] = f;
	}
	// a[x] - a[y] = v
	void merge(int x, int y, int v) {
		int px = find(x);
		int py = find(y);
		if(px != py) {
			d[px] = d[y] + v - d[x];
			p[px] = py;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	// a[x] - a[y]
	int query(int x, int y) {
		return d[x] - d[y];
	}
};

void solve() {
	int n, q;
	cin >> n >> q;
	Union p(n);
	while(q--) {
		int op, x, y, z;
		cin >> op;
		if(!op) {
			cin >> x >> y >> z;
			p.merge(y, x, z);
		} else {
			cin >> x >> y;
			if(!p.same(x, y)) cout << "?\n";
			else cout << p.query(y, x) << '\n';
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