#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 200010;
const int mod = 998244353;

int n;
int a[N], b[N];
ll val[N];

/*
	思路： 包含 a[i] * b[i] 的区间有 i * (n - i + 1) 个（左端点有 i 种
		  选择，右端点有 (n - i + 1) 种选择，因此答案为
		  sum(a[i] * b[i] * i * (n - i + 1))。
		  令 val[i] = a[i] * i * (n - i + 1)，将 val 数组和 b 数组分别
		  从小到大排序、从大到小排序再分别相乘即可。
*/
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		val[i] = 1ll * a[i] * i * (n - i + 1);
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	sort(b + 1, b + 1 + n, greater<int>());
	sort(val + 1, val + 1 + n);
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += val[i] % mod * b[i] % mod;
		ans %= mod;
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