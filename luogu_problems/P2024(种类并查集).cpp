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
		p.resize(sz + 1);
		iota(p.begin() + 1, p.end(), 1);
	}
	int find(int x) {
		return x == p[x] ? p[x] : (p[x] = find(p[x]));
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

/*
	i: 和 i 同类
	i + n: 被 i 捕食 
	i + 2n: i 的天敌
*/
void solve() {
	int n, k, cnt = 0;
	cin >> n >> k;
	Union p(n * 3);
	while(k--) {
		int t, x, y;
		cin >> t >> x >> y;
		if(x > n || y > n) {
			cnt += 1;
			continue;
		}

		if(t == 1) {	// x、y 是同类
			// y 被 x 捕食或者 y 是 x 的天敌
			if(p.same(y, x + n) || p.same(y, x + n * 2)) {
				cnt += 1;
				continue;
			}
			p.merge(x, y);
			p.merge(x + n, y + n);
			p.merge(x + n * 2, y + n * 2);
		} else {	// x 捕食 y
			if(x == y) {
				cnt += 1;
				continue;
			}
			// x、y 是同类或者 y 是 x 的天敌
			if(p.same(x, y) || p.same(y, x + n * 2)) {
				cnt += 1;
				continue;
			}
			p.merge(y, x + n);	// y 被 x 捕食
			p.merge(x, y + n * 2);	// x 是 y 的天敌
			p.merge(x, y + n + n);	// x 被（被y 捕食的动物）捕食
			p.merge(y + n, x + n * 2);	// （被y 捕食的动物）是 x 的天敌
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