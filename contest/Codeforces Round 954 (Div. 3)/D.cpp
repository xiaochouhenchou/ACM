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
	string s;
	cin >> n >> s;
	ll ans = INF;
	for(ll i = 0, j, k, res; i < n - 1; i++) {
		vector<ll> num;
		j = 0, k = 0;
		for(j = 0, k = 0; j < n - 1; j++) {
			if(j == i) continue;
			res = 0;
			while(k <= j) {
				res = res * 10 + s[k] - '0';
				k += 1;
			}
			num.push_back(res);
		}
		res = 0;
		while(k < n) {
			res = res * 10 + s[k] - '0';
			k += 1;
		}
		num.push_back(res);

		// cout << i << '\n';
		// for(auto x : num) {
		// 	cout << x << ' ';
		// }
		// cout << '\n';

		ll tmp = num[0];
		for(ll u = 1; u < sz(num); u++) {
			if(min(tmp, num[u]) <= 1) tmp *= num[u];
			else tmp += num[u];
		}
		ans = min(ans, tmp);
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