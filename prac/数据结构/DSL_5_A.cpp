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
	int n, t;
	cin >> n >> t;
	map<int, int> mp;
	for(int i = 1, l, r; i <= n; i++) {
		cin >> l >> r;
		mp[l] += 1;
		mp[r] -= 1;
	}
	int cnt = 0, ans = 0;
	for(auto [x, c] : mp) {
		cnt += c;
		ans = max(ans, cnt);
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