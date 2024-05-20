#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

/*
	思路： 
		a[k] | a[i], a[k] | a[j] -> a[k] | gcd(a[i], a[j])
		令 cnt[g] 为 a 中 g 出现的次数，f[g] 为 gcd = g 的 (i, j) 对数，
		s[g] = cnt[g] + cnt[2g] + ... cnt[kg]，那么 
		f[g] = s[g] * (s[g] - 1) / 2 - f[2g] - f[3g] - ...  
		计算出来 f[g] 之后，我们只需要把能被 a 中出现过的数 x (cnt[x] > 1)
		整除的 g 的 f[g] 排除，累加剩余的 f[g] 即可。
		复杂度：调和级数 O(nlogn)
*/
void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), cnt(n + 1), vis(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] += 1;
	}

	vector<ll> f(n + 1), s(n + 1);
	for(int g = 1; g <= n; g++) {
		for(int kg = g; kg <= n; kg += g) {
			s[g] += cnt[kg];
		}
	}
	
	for(int g = n; g; g--) {
		f[g] = s[g] * (s[g] - 1) / 2;
		for(int kg = g + g; kg <= n; kg += g) {
			f[g] -= f[kg];
		}
	}
	ll ans = 0;
	for(int x = 1; x <= n; x++) {
		if(!cnt[x]) continue;
		for(int y = x; y <= n; y += x) {
			vis[y] = 1;
		}
	}
	for(int g = 1; g <= n; g++) {
		if(!vis[g]) ans += f[g];
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	// init(1e6);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}