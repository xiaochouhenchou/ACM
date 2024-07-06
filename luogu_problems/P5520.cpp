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
	int t, n, m, p;
	cin >> t >> n >> m >> p;
	ll ans = 1;
	for(int i = n - m * 2 + 2; i <= n - m + 1; i++) {
		ans = ans * i % p;
	}
	if(n < m) ans = 0;
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