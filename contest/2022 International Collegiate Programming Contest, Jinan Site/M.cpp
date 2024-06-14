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
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	auto calc = [&](ll x, ll y) {
		ll r = 0, res = 0;
		while(x && y) {
			if(x % 10 + y % 10 + r >= 10) {
				res += 1;
				r = 1;
			} else {
				r = 0;
			}
			x /= 10, y /= 10;
		}
		while(x) {
			if(x % 10 + r >= 10) {
				res += 1;
				r = 1;
			} else {
				r = 0;
			}
			x /= 10;
		}
		while(y) {
			if(y % 10 + r >= 10) {
				res += 1;
				r = 1;
			} else {
				r = 0;
			}
			y /= 10;
		}
		return res;
	};
	sort(a.begin(), a.end());
	ll sum = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		ans += calc(sum, a[i]);
		sum += a[i];
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