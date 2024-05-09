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
	int n;
	while(cin >> n, n) {
		vector<ll> h(n + 1), l(n + 1), r(n + 1);
		for(int i = 1; i <= n; i++) {
			cin >> h[i];
			l[i] = r[i] = i;
		}
		for(int i = 1; i <= n; i++) {
			while(l[i] - 1 >= 1 && h[l[i] - 1] >= h[i]) {
				l[i] = l[l[i] - 1];
			}
		}
		for(int i = n; i; i--) {
			while(r[i] + 1 <= n && h[r[i] + 1] >= h[i]) {
				r[i] = r[r[i] + 1];
			}
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++) {
			ans = max(ans, (r[i] - l[i] + 1) * h[i]);
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