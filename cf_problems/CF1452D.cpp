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

/*
	思路： 对于每个 n 对应的答案不同的类型的问题，一般是递推解决，关键
		  找子问题和原问题的关系。 
		  如果最左边的选择的塔是 x，那么它的半径一定为 x。因为半径大于
		  x 会覆盖到 0，小于 x 又会使得左边某个点没被覆盖。选择好 x 
		  的位置以后，因为每个村庄都只能被覆盖一次，因此原问题就转变成
		  n - (2x + 1) 的子问题。这样的话，每一种选择塔的方式对应的
		  覆盖所有村庄的方法都是唯一的，即原问题变成求用若干长度奇数的
		  区间将 n 个点覆盖的方案数(再除以总方案数即为概率)。 
		  令 f[i] 为覆盖 i 个点的方案数，那么 f[i] = f[i - 1] + 
		  f[i - 3] + ...，用奇偶前缀和优化即可。
*/

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
	int n;
	cin >> n;
	vector<int> f(n + 1), sum(2);
	f[0] = sum[0] = 1;
	int p = 1;
	for(int i = 1; i <= n; i++) {
		f[i] = sum[!(i % 2)];
		sum[i % 2] += f[i];
		sum[i % 2] %= mod;
		p = p * 2 % mod;
	}
	int ans = 1ll * f[n] * qpow(p, mod - 2) % mod;
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