#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 2000010;

ll ceil(ll x, ll y) {
	return x >= 0 ? (x + y - 1) / y : x / y;
}

void solve() {
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	auto check = [&](ll b, ll g) {
		ll y = b * g;
		for(ll x = ceil(b + 1, y) * y; x <= b + n; x += y) {
			if(__gcd(x, b) == g) {
				ans += 1;
			}
		}
	};

	for(ll b = 1; b <= m; b++) {
		for(ll i = 1; i <= b / i && b * i <= b + n; i++) {
			if(b % i == 0) {
				check(b, i);
				if(i != b / i) check(b, b / i);
			}
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
