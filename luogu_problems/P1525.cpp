#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// 将每对关系按照 c 从大到小排序，然后贪心地让每对 a、b 处于不同监狱。
// 种类并查集： i 表示和 i 在同一个监狱的集合，i + n 表示和 i 不在
// 同一个监狱的集合，如果 a、b 不在同一个监狱那么 merge(a, b + n), 
// merge(a + n, b)

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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> v;
	for(int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.emplace_back(c, a, b);
	}
	sort(v.rbegin(), v.rend());
	Union p(n * 2);
	for(auto [c, a, b] : v) {
		if(p.same(a, b)) {
			cout << c << '\n';
			return;
		}
		p.merge(a, b + n);
		p.merge(a + n, b);
	}
	cout << 0 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}