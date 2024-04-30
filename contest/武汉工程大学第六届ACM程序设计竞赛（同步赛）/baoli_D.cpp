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
const int mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2);
	vector<int> s(n + 2), p(n + 2);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = (s[i - 1] + a[i]) % mod;
		p[i] = (p[i - 1] + s[i]) % mod;
	}
	LL ans = 0;
	for(int l = 1; l <= n; l++) {
		for(int r = l; r <= n; r++) {
			int x = *max_element(a.begin() + l, a.begin() + r + 1)
			- *min_element(a.begin() + l, a.begin() + r + 1);
			ans = (ans + 1ll * x * (s[r] - s[l - 1]) % mod) % mod;
			ans = (ans + mod) % mod;
		}
	}
	cout << ans << '\n';

	// // for(int i = 1; i <= n; i++) {
	// // 	cout << s[i] << " \n"[i == n];
	// // }
	// // for(int i = 1; i <= n; i++) {
	// // 	cout << p[i] << " \n"[i == n];
	// // }

	// vector<int> stk{0};
	// a[0] = inf;
	
	// LL ans = 0;
	// for(int r = 1; r <= n; r++) {
	// 	while(sz(stk) && a[stk.back()] <= a[r]) {
	// 		stk.pop_back();
	// 	}
	// 	stk.push_back(r);
	// 	LL res = 0;
	// 	for(int i = 1; i < sz(stk); i++) {
	// 		for(int j = stk[i - 1]; j < stk[i]; j++) {
	// 			res += 1ll * (s[r] - s[j]) * a[stk[i]] % mod;
	// 			res %= mod;
	// 		}
	// 	}
	// 	// cout << r << ' ' << res << '\n';
	// 	ans = (ans + res) % mod;
		
	// 	// cout << "--------------------\n";
	// }

	// stk.clear();
	// stk.push_back(0);
	// a[0] = -inf;
	// for(int r = 1; r <= n; r++) {
	// 	while(sz(stk) && a[stk.back()] >= a[r]) {
	// 		stk.pop_back();
	// 	}
	// 	stk.push_back(r);
	// 	LL res = 0;
	// 	for(int i = 1; i < sz(stk); i++) {
	// 		for(int j = stk[i - 1]; j < stk[i]; j++) {
	// 			res += 1ll * (s[r] - s[j]) * a[stk[i]] % mod;
	// 			res %= mod;
	// 		}
	// 	}
	// 	// cout << r << ' ' << res << '\n';
	// 	ans = (ans - res) % mod;
	// 	ans = (ans + mod) % mod;
		
	// 	// cout << "--------------------\n";
	// }
	// cout << ans << '\n';
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
