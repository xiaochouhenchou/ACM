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
	vector<int> c(35);
	for(int i = 0, a; i < n; i++) {
		cin >> a;
		c[__lg(a)] += 1;
	}
	while(q--) {
		int b;
		cin >> b;
		int ans = 0;
		for(int i = 30; i >= 0; i--) {
			int tmp = min(c[i], b / (1 << i));
			b -= tmp * (1 << i);
			ans += tmp;
		}
		if(b) ans = -1;
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