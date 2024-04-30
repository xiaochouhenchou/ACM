#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const int mod = 1e9 + 9;

LL qpow(LL a, LL b) {
	LL res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res % mod;
}

void solve() {
	LL m, k;
	cin >> m >> k;
	LL f = 0, g = 0;
	LL leaf_cnt = 1, ans = 0;
	for(int i = 1; i <= k; i++) {
		LL inv = qpow(leaf_cnt, mod - 2);
		f = (g * inv % mod + 1) % mod;
		LL d = g * inv % mod;
		g = (g + (m - 1) * d % mod + m) % mod;
		ans = (ans + f * m % mod) % mod;
		leaf_cnt = (leaf_cnt - 1 + m) % mod;
	}	
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;	
	while(t--) {
		solve();
	}
	return 0;
}
