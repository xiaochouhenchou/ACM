#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 998244353;

ll qpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res % mod;
}

void solve() {
	ll n;
	cin >> n;
	string s = to_string(n);


	ll c = qpow(10, sz(s));
	ll x = n % mod * qpow(c - 1, mod - 2) % mod;
	ll cn = qpow(c, n);
	ll res = x * cn % mod;
	res = ((res - x) % mod + mod) % mod;
	cout << res << '\n';

	// ll ans = 0;
	// for(int i = 0; i < n; i++) {
	// 	ans = (ans * c % mod + n) % mod;
	// }
	// cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}