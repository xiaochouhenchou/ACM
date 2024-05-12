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
	ll r;
	cin >> r;
	ll ans = 0, t = 0;
	for(ll x = 0; x <= r; x++) {
		for(ll y = ceil(sqrtl(r * r - x * x)); ; y++) {
			if(r + 1 - sqrtl(x * x + y * y) > 0) {
				ans += 1;
				// cout << x << ' ' << y << '\n';
				if(!x || !y) t += 1;
			} else {
				break;
			}
		}
	}	
	ans = ans * 4 - t * 2;
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