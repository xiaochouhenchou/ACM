#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 1e9 + 7;

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
	ll l, r, k;
	cin >> l >> r >> k;
	if(k >= 10) {
		cout << 0 << '\n';
		return;
	}

	ll val = 9 / k + 1;
	ll ans = (qpow(val, r) - qpow(val, l)) % mod;
	ans =  (ans + mod) % mod;
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