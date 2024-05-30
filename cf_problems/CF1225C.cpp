#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	ll n, p;
	cin >> n >> p;
	if(n <= p) {
		cout << -1 << '\n';
		return;
	}

	auto check = [&](ll k) {
		ll x = n - k * p;
		ll cnt = __builtin_popcountll(x);
		return cnt <= k && k <= x;
	};

	for(ll k = 1; n - k * p >= 1; k++) {
		if(check(k)) {
			cout << k << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}