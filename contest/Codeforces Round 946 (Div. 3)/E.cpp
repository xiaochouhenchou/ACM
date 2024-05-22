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
	ll n, x, m = 0;
	cin >> n >> x;
	vector<ll> c(n + 1), h(n + 1);
	for(ll i = 1; i <= n; i++) {
		cin >> c[i] >> h[i];
		m += h[i];
	}
	vector<ll> f(m + 1, INF);
	f[0] = 0;
	for(ll i = 1; i <= n; i++) {
		for(ll j = m; j >= 0; j--) {
			if(j + h[i] <= m && f[j] + c[i] <= (i - 1) * x) {
				f[j + h[i]] = min(f[j + h[i]], f[j] + c[i]);
			}
		}
	}
	ll ans = 0;
	for(ll j = 0; j <= m; j++) {
		if(f[j] != INF) ans = max(ans, j);
	}
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