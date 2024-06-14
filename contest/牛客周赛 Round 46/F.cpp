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

ll C(ll a, ll b) {
	if(a < b) return 0ll;

	ll res = 1;
	for(ll i = 1; i <= b; i++) {
		res = res * (a - b + i) % mod;
		res = res * qpow(i, mod - 2) % mod;
	}
	return res % mod;
}

void solve() {
	int x, y;
	cin >> x >> y;
	vector<PII> p;
	for(int i = 2; i <= x / i; i++) {
		if(x % i == 0) {
			int c = 0;
			while(x % i == 0) x /= i, c += 1;
			p.emplace_back(i, c);
		}
	}
	if(x > 1) p.emplace_back(x, 1);
	
	ll ans = 1;
	for(auto [e, d] : p) {
		ans = ans * C(y + d - 1, d) % mod;
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