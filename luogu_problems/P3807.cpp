#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// C(a, b) % p = C(a / p, b / p) * C(a % p, b % p) % p

ll qpow(ll a, ll b, ll mod) {
	ll res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res % mod;
}

ll C(ll a, ll b, ll mod) {
	if(a < b) return 0ll;

	ll res = 1;
	for(int i = 1, j = a; i <= b; i++, j--) {
		res = res * j % mod;
		res = res * qpow(i, mod - 2, mod) % mod;
	}
	return res % mod;
}

ll lucas(ll a, ll b, ll mod) {
	if(a < mod && b < mod) {
		return C(a, b, mod);
	}

	return lucas(a / mod, b / mod, mod) * lucas(a % mod, b % mod, mod) % mod;
}

void solve() {
	ll n, m, p;
	cin >> n >> m >> p;
	cout << lucas(n + m, n, p) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}