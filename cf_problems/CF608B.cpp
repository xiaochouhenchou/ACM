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
	string a, b;
	cin >> a >> b;
	int n = sz(a), m = sz(b);
	a = " " + a;
	b = " " + b;
	vector<vector<int>> cnt(n + 1, vector<int>(2));
	for(int i = 1; i <= n; i++) {
		cnt[i][0] = cnt[i - 1][0] + (a[i] == '0');
		cnt[i][1] = cnt[i - 1][1] + (a[i] == '1');
	}
	ll ans = 0;
	for(int i = 1; i <= m; i++) {
		int l = max(n - m + i, 1);
		int r = min(i, n);
		int v = b[i] - '0';
		ans += (cnt[r][0] - cnt[l - 1][0]) * abs(0 - v);
		ans += (cnt[r][1] - cnt[l - 1][1]) * abs(1 - v);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}