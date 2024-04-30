#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const int mod = 1e9 + 7;

void solve() {	
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<int> va, vb, ta, tb;
	LL ans = INF;
	auto dfs = [&](auto dfs, LL cur, int len_n, int len_m, LL cost) -> void {
		if(!len_n && !len_m) {
			if(ans > cost) {
				ans = cost;
				va = ta, vb = tb;
			}
			return;
		}

		if(len_n) {
			if(len_n >= cur + 1) {
				ta.push_back(cur);
				dfs(dfs, cur * 2, len_n - cur, len_m, cost + a);
			} else {
				ta.push_back(len_n);
				dfs(dfs, cur + len_n, 0, len_m, cost);
			}
			ta.pop_back();
		}
		if(len_m) {
			if(len_m >= cur + 1) {
				tb.push_back(cur);
				dfs(dfs, cur * 2, len_n, len_m - cur, cost + b);
			} else {
				tb.push_back(len_m);
				dfs(dfs, cur + len_m, len_n, 0, cost);
			}
			tb.pop_back();
		}
	};
	dfs(dfs, 1, n, m, 0);
	cout << ans << ' ' << sz(va) - 1 << ' ' << sz(vb) - 1 << '\n';
	for(int i = 0; i < sz(va); i++) {
		cout << va[i] << " \n"[i == sz(va) - 1];
	}
	for(int i = 0; i < sz(vb); i++) {
		cout << vb[i] << " \n"[i == sz(vb) - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;	
	while(t--) {
		solve();
	}
	return 0;
}
