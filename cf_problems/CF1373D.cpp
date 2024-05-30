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
	int n;
	cin >> n;
	vector<vector<ll>> s(n + 1, vector<ll>(2));
	for(int i = 1, a; i <= n; i++) {
		cin >> a;
		s[i][0] = s[i - 1][0] + (i % 2 == 0 ? a : 0);
		s[i][1] = s[i - 1][1] + (i % 2 == 1 ? a : 0);
	}
	ll ans = s[n][1], maxv = 0;
	ll pre[2] = {0};
	for(int i = 1; i <= n; i++) {
		maxv = max(maxv, s[i][0] - s[i][1] + pre[i & 1]);
		pre[i & 1] = max(pre[i & 1], s[i][1] - s[i][0]);
	}
	// cout << ans << ' ' << maxv << '\n';
	ans += maxv;
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