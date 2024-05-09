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
	ll m, rp = 0, a[] = {0, 3, 5, 10, -1};
	cin >> m;
	while(m--) {
		ll t, x;
		cin >> t >> x;
		rp = (rp + a[t] * x % 7) % 7;
		rp = (rp + 7) % 7;
	}
	cout << rp << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}