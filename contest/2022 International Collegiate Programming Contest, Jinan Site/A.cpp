#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// x -> y 的最小操作次数
ll calc(ll x, ll y) {
	if(x <= y) {
		return y - x;
	}
	ll res = 0;
	while(x / 2 >= y) {
		res += 1;
		x /= 2;
	}
	return min(res + x - y, res + 1 + y - x / 2);
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), b(n);
	for(auto &x : a) {
		cin >> x;
	}
	// 枚举 x，x / 2， x / 4，...，计算其它数变成它的最少操作次数，
	// 并去掉最大的 m 个，取最小值
	ll ans = INF;
	for(int i = 0; i < n; i++) {
		ll x = a[i];
		while(x > 0) {
			for(int j = 0; j < n; j++) {
				b[j] = calc(a[j], x);
			}
			sort(b.begin(), b.end());
			ll res = 0;
			for(int j = 0; j < n - m; j++) {
				res += b[j];
			}
			ans = min(ans, res);
			x /= 2;
		}
	}
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