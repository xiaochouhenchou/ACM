#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const double eps = 1e-8;
const int mod = 1e9 + 9;

void solve() {
	int n, L, R;
	cin >> n >> L >> R;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());
	LL ans = 0;
	for(int i = 1; i <= n; i++) {
		auto l = lower_bound(a.begin() + 1, a.begin() + i, 
			L - a[i]) - a.begin();
		auto r = upper_bound(a.begin() + 1, a.begin() + i,
			R - a[i]) - a.begin();
		// cout << a[i] << ' ' << l << ' ' << r << '\n';
		if(l <= r) ans += r - l;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;	
	while(t--) {
		solve();
	}
	return 0;
}
