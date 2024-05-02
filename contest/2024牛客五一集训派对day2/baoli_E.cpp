#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const ll mod = 998244353;

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
	ll a, b, c, d, X, Y;
	cin >> a >> b >> c >> d >> X >> Y;	
	auto get_primes = [](ll v, map<ll, ll> &mp) {
		for(ll i = 2; i <= v / i; i++) {
			if(v % i == 0) {
				ll c = 0;
				while(v % i == 0) v /= i, c++;
				mp[i] = c;
			}
		}
		if(v > 1) mp[v] = 1;
	};
	auto ceil = [](ll x, ll y) {
		return x >= 0 ? (x + y - 1) / y : x / y;
	};

	map<ll, ll> px, py;
	get_primes(X, px);
	get_primes(Y, py);

	ll ans = 1;
	for(ll i = a; i <= b; i++) {
		for(auto [p, k1] : px) {
			if(!py.count(p)) continue;
			ll k2 = py[p], res = 1;
			for(int j = c; j <= d; j++) {
				ll t = min(k1 * i, k2 * j);
				// cout << p << ' ' << t << '\n';
				res = res * qpow(p, t) % mod;
			}
			// cout << res << '\n';
			// cout << "---------------\n";
			ans = ans * res % mod;
		}
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
