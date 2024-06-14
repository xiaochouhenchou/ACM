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
	cin >> n;
	vector<PII> p(n + 1);	// b a
	for(int i = 1; i <= n; i++) {
		cin >> p[i].y;
	}
	for(int i = 1; i <= n; i++) {
		cin >> p[i].x;
	}
	sort(p.begin() + 1, p.end());
	vector<ll> sum(n + 1), suf(n + 2);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + 1ll * p[i].x * p[i].y;
	}
	for(int i = n; i; i--) {
		suf[i] = suf[i + 1] + p[i].y;
	}
	int q;
	cin >> q;
	while(q--) {
		ll k;
		cin >> k;
		int idx = upper_bound(p.begin(), p.end(), PII(k, inf)) - p.begin();
		ll ans = sum[idx - 1] + suf[idx] * k;
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