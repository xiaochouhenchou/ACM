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
	ll n;
	cin >> n;
	auto check = [&](ll k) {
		ll cur = n, res = 0;
		while(cur > 0) {
			ll tmp = min(k, cur);
			cur -= tmp;
			res += tmp;

			cur -= cur / 10;
		}
		return res * 2 >= n;
	};
	ll l = 1, r = n;
	while(l < r) {
		ll mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << r << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}