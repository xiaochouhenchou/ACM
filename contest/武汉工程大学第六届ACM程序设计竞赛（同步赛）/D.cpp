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
	LL n;
	cin >> n;
	vector<LL> a(n + 2);
	vector<LL> s(n + 2), p(n + 2);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = (s[i - 1] + a[i]) % mod;
		p[i] = (p[i - 1] + s[i]) % mod;
	}

	auto add = [&](LL a, LL b) {
		a = (a + b) % mod;
		return a;
	};
	auto sub = [&](LL a, LL b) {
		a = (a - b) % mod;
		a = (a + mod) % mod;
		return a;
	};

	vector<int> stk{0};
	a[0] = inf;
	auto get_sum = [&](int l, int r) {	
		LL res = p[r - 1] * a[r] % mod;
		if(l >= 1) {
			res = sub(res, p[l - 1] * a[r] % mod);
		}
		return res % mod;
	};
	
	LL ans = 0, sum1 = 0, sum2 = 0;
	for(int r = 1; r <= n; r++) {
		while(sz(stk) && a[stk.back()] <= a[r]) {
			int x = stk[sz(stk) - 2];
			int y = stk[sz(stk) - 1];			
			sum1 = sub(sum1, a[y] * (y - x) % mod);
			sum2 = sub(sum2, get_sum(x, y));
			stk.pop_back();
		}
		sum1 = add(sum1, a[r] * (r - stk.back()) % mod);
		sum2 = add(sum2, get_sum(stk.back(), r));
		LL res = sum1 * s[r] % mod;
		res = sub(res, sum2);
		ans = add(ans, res);

		stk.push_back(r);
	}

	stk.clear();
	stk.push_back(0);
	a[0] = -inf, sum1 = sum2 = 0;
	for(int r = 1; r <= n; r++) {
		while(sz(stk) && a[stk.back()] >= a[r]) {
			int x = stk[sz(stk) - 2];
			int y = stk[sz(stk) - 1];			
			sum1 = sub(sum1, a[y] * (y - x) % mod);
			sum2 = sub(sum2, get_sum(x, y));
			stk.pop_back();
		}
		sum1 = add(sum1, a[r] * (r - stk.back()) % mod);
		sum2 = add(sum2, get_sum(stk.back(), r));
		LL res = sum1 * s[r] % mod;
		res = sub(res, sum2);
		ans = sub(ans, res);

		stk.push_back(r);
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
