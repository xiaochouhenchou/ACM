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

ll qmi(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

void solve() {
	ll m, a, b, c;
	cin >> m >> a >> b >> c;
	ll inv = qmi(m * m % mod, mod - 2);
	ll p1 = 3ll * (m - 1) * inv % mod;
	ll p2 = inv;
	ll p3 = m * m - 3ll * m + 2ll;
	p3 = p3 % mod * inv % mod;
	ll ans = p1 * b % mod;
	ans = (ans + p2 * c % mod) % mod;
	ans = (ans + p3 * a % mod) % mod;
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