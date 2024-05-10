#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

ll dfs(ll l, ll r, ll x) {
	if(l == r) {
		return r;
	}
	ll mid = (l + r) / 2;
	if(x % 2 == 0) {	// x 在 [l, mid]
		return dfs(l, mid, x / 2);
	} 	
	// x 在 [mid + 1, r]
	return dfs(mid + 1, r, x / 2);
}

void solve() {
	ll n, m;
	cin >> n >> m;
	while(m--) {
		ll x;
		cin >> x;
		cout << dfs(0, (1ll << n) - 1, x) << '\n';
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