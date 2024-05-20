#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 1e9 + 7;

/*
	思路: 考虑第 j 列和第 c - j + 1 列的 1 的个数 cnt，如果 cnt > 2
		 则无解，方案数为 0。 如果 cnt <= 1，那么无论怎么翻转矩阵的某些
		 行都不会影响方案的合法性。因此考虑 cnt = 2 的情况即可。
		 如果第 j 和 c - j + 1 列的 1 分别位于 x、y 行，那么有两种情况：
		 	1. x、y 的 1 位于同一列。
		 	2. x、y 的 1 位于不同列。
		 如果是情况 1，那么方案合法只能是 （翻转 x，y 不动）（x 不动，翻转 y）；
		 如果是情况 2，那么方案合法只能是 （x 不动，y 不动）（翻转 x，翻转 y）。
		 问题可以转化成图论问题。有 2r 个点，i 表示不翻转第 i 行，i + r 表示翻转第
		 i 行，那么根据上述关系得到两条边： (x + r, y) (x, y + r) 或 
		 (x, y) (x + r, y + r)
		 如果 i 和 i + r 在同一个连通块则无解，方案数为 0。如果得到的图中的连通块
		 有 2x 个，方案数即为 2^x。 因为 2n 个
*/

struct disjointSet {
	int n, cnt;
	vector<int> p;
	disjointSet() {}
	disjointSet(int sz) : n(sz), cnt(sz) {
		p.resize(sz + 1);
		iota(p.begin() + 1, p.end(), 1);
	}
	int find(int x) {
		return p[x] == x ? x : p[x] = find(p[x]);
	}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if(x != y) {
			p[x] = y;
			cnt -= 1;
		}
	}
};

void solve() {
	int r, c;
	cin >> r >> c;
	vector<string> s(r + 1);
	for(int i = 1; i <= r; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
	}
	vector<vector<int>> idx(c + 1);
	for(int j = 1; j <= c; j++) {
		for(int i = 1; i <= r; i++) {
			if(s[i][j] == '1') {
				idx[j].push_back(i);
			}
		}
	}
	disjointSet p(r + r);
	for(int j = 1; j <= c; j++) {
		if(sz(idx[j]) + sz(idx[c - j + 1]) > 2) {
			cout << 0 << '\n';
			return;
		}
	}
	for(int j = 1; j <= c; j++) {
		if(j != c - j + 1 && sz(idx[j]) + sz(idx[c - j + 1]) == 2) {
			int x = -1, y = -1;
			for(auto e : idx[j]) {
				if(x == -1) x = e;
				else y = e;
			}
			for(auto e : idx[c - j + 1]) {
				if(x == -1) x = e;
				else y = e;
			}		
			// cout << x << ' ' << y << endl;
			if(sz(idx[j]) == 2 || sz(idx[c - j + 1]) == 2) {
				p.merge(x + r, y);
				p.merge(x, y + r);
			} else {
				p.merge(x, y);
				p.merge(x + r, y + r);
			}
		}
	}
	for(int i = 1; i <= r; i++) {
		if(p.find(i) == p.find(i + r)) {
			cout << 0 << '\n';
			return;
		}
	}
	ll ans = 1, x = p.cnt / 2;
	for(int i = 0; i < x; i++) ans = ans * 2 % mod;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}