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
	vector<int> p, d;	// d[x] = a[x] - a[p[x]]
	Union() {}
	Union(int sz) : n(sz) {
		p.resize(sz + 1);
		d.resize(sz + 1);
		iota(p.begin(), p.end(), 0);
	}
	int find(int x) {
		if(x == p[x]) return p[x];

		int fa = find(p[x]);
		d[x] += d[p[x]];
		return p[x] = fa;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
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
	int query(int x, int y) {
		return d[x] - d[y];
	}
};

void solve() {
	int n, m, ok = 1;
	cin >> n >> m;
	Union p(n);
	while(m--) {
		int x, y, v;
		cin >> x >> y >> v;
		x -= 1;

		if(p.same(x, y)) {
			if(p.query(y, x) != v) {
				ok = 0;
			}
		} else {
			p.merge(y, x, v);
		}
	}
	cout << (ok ? "true\n" : "false\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}