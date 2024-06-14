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
	vector<int> a(n + 1), b(n + 2);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n + 1; i++) {
		cin >> b[i];
	}
	ll ans = 0;
	int cost = inf;
	for(int i = 1; i <= n; i++) {
		int x = a[i], y = b[i];
		if(x > y) swap(x, y);
		if(x <= b[n + 1] && b[n + 1] <= y) {
			cost = 1;
		} else {
			cost = min(cost, abs(x - b[n + 1]) + 1);
			cost = min(cost, abs(y - b[n + 1]) + 1);
		}
		ans += y - x;
	}
	ans += cost;
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