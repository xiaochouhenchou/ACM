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
	auto floor = [](ll x, ll y) {
		return x >= 0 ? x / y : (x + y - 1) / y;
	};

	map<ll, ll> px, py;
	get_primes(X, px);
	get_primes(Y, py);

	ll ans = 1;
	for(auto [p, k1] : px) {
		if(!py.count(p)) continue;

		ll k2 = py[p];
		ll sum = 0;
		for(ll i = a; i <= b; i++) {
			ll x = floor(k1 * i, k2);
			if(x < c) {
				sum += k1 * i * (d - c + 1);
			} else if(x > d) {
				sum += (c + d) * (d - c + 1) / 2 * k2;
			} else {
				sum += (c + x) * (x - c + 1) / 2 * k2;
				sum += k1 * i * (d - x);
			}
			sum = sum % (mod - 1);	// phi[mod] = mod - 1，mod 是质数
		}		
		ans = ans * qpow(p, sum) % mod;
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
