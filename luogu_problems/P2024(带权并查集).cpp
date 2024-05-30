#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

/*
	d[x] = x 和 p[x] 的关系
	d[x] = 0，同类
	d[x] = 1，x 捕食 p[x]
	d[x] = 2, x 被 p[x] 捕食
*/
struct Union {
	int n;
	vector<int> p, d;
	Union() {}
	Union(int sz) : n(sz) {
		p.resize(sz + 1);
		d.resize(sz + 1);
		iota(p.begin() + 1, p.end(), 1);
	}
	int find(int x) {
		if(x == p[x]) return p[x];

		int fa = find(p[x]);
		d[x] = (d[x] + d[p[x]]) % 3;
		return p[x] = fa;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	void merge(int x, int y, int v) {
		int px = find(x);
		int py = find(y);
		if(px != py) {
			d[px] = ((d[y] + v - d[x]) % 3 + 3) % 3;
			p[px] = py;
		}
	}
	int query(int x, int y) {
		if(!same(x, y)) return inf;
		return ((d[x] - d[y]) % 3 + 3) % 3;
	}
};

void solve() {
	int n, k, cnt = 0;
	cin >> n >> k;
	Union p(n);
	while(k--) {
		int op, x, y;
		cin >> op >> x >> y;
		if(x > n || y > n) {
			cnt += 1;
			continue;
		}

		if(op == 1) {
			int q = p.query(x, y);
			if(q == 1 || q == 2) {
				cnt += 1;
				continue;
			}
			p.merge(x, y, 0);
		} else {
			if(x == y) {
				cnt += 1;
				continue;
			}
			int q = p.query(x, y);
			if(q == 0 || q == 2) {
				cnt += 1;
				continue;
			}
			p.merge(x, y, 1);
		}
	}	
	cout << cnt << '\n';	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}