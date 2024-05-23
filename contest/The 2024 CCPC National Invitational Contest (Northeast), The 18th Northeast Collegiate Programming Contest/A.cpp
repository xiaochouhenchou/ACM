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
	ll x, k;
	cin >> x >> k;
	if(x == 1) {
		cout << 1 << '\n';
		return;
	}
	
	ll ans = 0, last_x = 0;
	while(true) {
		if(x * x == last_x) {
			ans += 1;
		} else {
			ans += k + 1;
		}
		if(!k) break;
		last_x = x;
		x = floor(sqrt(x));
		k -= 1;
		if(x == 1) {
			ans += 1;
			break;
		}
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