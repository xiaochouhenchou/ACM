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
	对于询问 (a, b, c, d)，用二维前缀和的答案为 
	s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1]
	= (s[c][d] - s[c][b - 1]) - (s[a - 1][d] - s[a - 1][b - 1])
	考虑离线做法，将询问中的坐标按照横坐标排序，从小到大枚举坐标，令 
	ans[i][x] = sum[d] - sum[b - 1]，表示 [0, x] 的询问 i 的答案，则
	ANS[i] = ans[i][c] - ans[i][a - 1]。 用树状数组维护 sum 即可。
*/
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
	int n, m;
	cin >> n >> m;
	vector<PII> point;
	vector<tuple<int, int, int, int, int>> query;
	for(int i = 0, x, y; i < n; i++) {
		cin >> x >> y;
		x += 1, y += 1;
		point.emplace_back(x, y);
	}
	for(int i = 0, a, b, c, d; i < m; i++) {
		cin >> a >> b >> c >> d;
		a += 1, b += 1, c += 1, d += 1;
		query.emplace_back(a - 1, b, d, i, -1);
		query.emplace_back(c, b, d, i, 1);
	}
	sort(point.begin(), point.end());
	sort(query.begin(), query.end());
	bitTree tr(10000000 + 1);
	vector<int> ans(m);
	for(int i = 0, j = 0; i < sz(query); i++) {
		auto [x, b, d, id, sign] = query[i];
		while(j < n && point[j].x <= x) {
			tr.add(point[j].y, 1);
			j += 1;
		}
		ans[id] += sign * (tr.sum(d) - tr.sum(b - 1));
	}
	for(int i = 0; i < m; i++) {
		cout << ans[i] << '\n';
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