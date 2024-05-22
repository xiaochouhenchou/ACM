#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	set<PII> X, Y;
	vector<int> mp(n + 1);
	for(int i = 1, x, y; i <= n; i++) {
		cin >> x >> y;
		X.emplace(x, i);
		Y.emplace(y, i);
		mp[i] = 1;
	}
	int ans[2] = {0};
	int op = 0, l = 1, r = a, L = 1, R = b;
	while(m--) {
		int k;
		string t;
		cin >> t >> k;
		if(t[0] == 'U') {
			while(sz(X) && (X.begin()->x) <= l + k - 1) {
				ans[op] += mp[X.begin()->y];
				mp[X.begin()->y] = 0;
				X.erase(X.begin());
			}
			l += k;
		}
		if(t[0] == 'D') {
			while(sz(X) && (X.rbegin()->x) >= r - k + 1) {
				ans[op] += mp[X.rbegin()->y];
				mp[X.rbegin()->y] = 0;
				X.erase(prev(X.end()));
			}			
			r -= k;
		}
		if(t[0] == 'L') {
			while(sz(Y) && (Y.begin()->x) <= L + k - 1) {
				ans[op] += mp[Y.begin()->y];
				mp[Y.begin()->y] = 0;
				Y.erase(Y.begin());
			}
			L += k;
		}
		if(t[0] == 'R') {
			while(sz(Y) && (Y.rbegin()->x) >= R - k + 1) {
				ans[op] += mp[Y.rbegin()->y];
				mp[Y.rbegin()->y] = 0;
				Y.erase(prev(Y.end()));
			}
			R -= k;
		}
		op ^= 1;
	}
	cout << ans[0] << ' ' << ans[1] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}