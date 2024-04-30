#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const double eps = 1e-8;
const int mod = 1e9 + 7;

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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> e(n, vector<int>(n));
	vector<vector<int>> f(n, vector<int>(1 << n));
	while(m--) {
		int u, v;
		cin >> u >> v;
		e[u - 1][v - 1] += 1;
	}

	vector<int> ans(n);
	f[0][1] = 1;
	for(int j = 0; j < (1 << n); j++) {
		for(int i = 0; i < n; i++) {
			if(!(j >> i & 1)) {
				continue;
			}
			int cnt = 0;
			for(int k = 0; k < n; k++) {
				if(e[i][k] && !(j >> k & 1)) cnt += e[i][k];
			}
			if(!cnt) {
				ans[i] += f[i][j];
				ans[i] %= mod;
				continue;
			}

			int inv = qpow(cnt, mod - 2);
			for(int k = 0; k < n; k++) {
				if(e[i][k] && !(j >> k & 1)) {
					int tmp = 1ll * f[i][j] * e[i][k] % mod * inv % mod;
					f[k][j | (1 << k)] += tmp;
					f[k][j | (1 << k)] %= mod;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
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
