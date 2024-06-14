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

void solve() {
	int n;
	cin >> n;
	vector<ll> s(n + 1);
	vector<vector<ll>> cnt(31, vector<ll>(2));	
	vector<vector<ll>> con(31, vector<ll>(2));	
	for(int i = 1, a; i <= n; i++) {
		cin >> a;
		s[i] = s[i - 1] ^ a;
	}
	ll ans = 0;
	for(int r = 0; r <= n; r++) {
		for(int i = 0; i < 31; i++) {
			int v = s[r] >> i & 1;
			ll p = 1ll << i;
			ll res = cnt[i][!v] * p % mod * r % mod;
			res = (res + con[i][!v]) % mod;
			ans = (ans + res) % mod;

			cnt[i][v] = (cnt[i][v] + 1) % mod;
			con[i][v] = (con[i][v] + ((p * (-r)) % mod + mod) % mod) % mod;  
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