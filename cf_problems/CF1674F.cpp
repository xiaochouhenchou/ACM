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
		tr.resize(n + 1, 0);
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
	int n, m, q;
	cin >> n >> m >> q;
	vector<string> s(n + 1);
	bitTree tr(n * m);
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
		for(int j = 1; j <= m; j++) {
			if(s[i][j] == '*') {
				tr.add((j - 1) * n + i, 1);
			}
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		if(s[x][y] == '.') {
			tr.add((y - 1) * n + x, 1);
			s[x][y] = '*';
		} else {
			tr.add((y - 1) * n + x, -1);
			s[x][y] = '.';
		}
		int tol = tr.sum(n * m);
		int cnt = tr.sum(tol);
		// cout << tol << ' ' << cnt << '\n';
		cout << tol - cnt << '\n';
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