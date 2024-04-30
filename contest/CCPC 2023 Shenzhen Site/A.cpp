#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> b(n + 1);
	vector<PII> c;
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		c.emplace_back(b[i], i);
	}
	sort(c.begin(), c.end());
	vector<PII> op;
	auto dfs = [&](auto dfs, int l, int r, int sub) -> void {
		if(l == r) {
			int cur = sub;
			while(cur < c[r].x) {
				op.emplace_back(2, c[r].y);
				cur += 1;
			}
			return;
		}
		
		int mid = (l + r) / 2;
		int minv = c[mid + 1].x - sub;
		if(minv > 0) {
			for(int i = mid + 1; i <= r; i++) {
				op.emplace_back(2, c[i].y);
			}
			for(int i = 1; i < minv; i++) {
				op.emplace_back(1, sub + i);
			}			
		}
		dfs(dfs, mid + 1, r, sub + minv);
		dfs(dfs, l, mid, sub);
	};
	dfs(dfs, 0, n - 1, 0);
	cout << sz(op) << '\n';
	for(auto [t, x] : op) {
		cout << t << ' ' << x << '\n';
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