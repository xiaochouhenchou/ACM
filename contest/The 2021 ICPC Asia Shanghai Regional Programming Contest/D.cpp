#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

bool check(ll x) {
	ll sq = sqrtl(x);
	return sq * sq == x;
}

/*
	x = b / a，由题意得 qx^2 - px + q = 0，用求根公式算一算即可。
*/
void solve() {
	ll p, q;
	cin >> p >> q;
	ll delta = p * p - q * q * 4ll;
	if(delta < 0 || !check(delta)) {
		cout << 0 << ' ' << 0 << '\n';
	} else {
		// 输出了小数 wa 了！
		// cout << q * 2 << ' ' << p + sqrtl(delta) << '\n';
		ll a = q * 2, b = p + sqrtl(delta);
		cout << a << ' ' << b << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}