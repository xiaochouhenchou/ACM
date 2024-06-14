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
	int n, q;
	cin >> n >> q;
	vector<ll> v(n + 1), c(n + 1), f(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	while(q--) {
		ll a, b;
		cin >> a >> b;
		fill(f.begin() + 1, f.end(), -INF);

		ll ans = 0;
		ll c1 = 0, c2 = 0;
		for(int i = 1; i <= n; i++) {
			ll last_f = f[c[i]], tmp = -INF;
			tmp = max(tmp, b * v[i]);
			tmp = max(tmp, last_f + a * v[i]);
			if(c1 != c[i]) {
				tmp = max(tmp, f[c1] + b * v[i]);
			} else {
				tmp = max(tmp, f[c2] + b * v[i]);
			}
			
			if(tmp >= f[c1]) {
				if(c[i] != c1) {
					c2 = c1;
					c1 = c[i];
				}
			} else if(tmp > f[c2] && c[i] != c1) {
				c2 = c[i];
			}

			f[c[i]] = max(f[c[i]], tmp);
			ans = max(ans, f[c[i]]);
		}
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}