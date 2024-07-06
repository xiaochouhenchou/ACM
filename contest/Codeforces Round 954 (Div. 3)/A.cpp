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
	int x1, x2, x3, ans = inf;
	cin >> x1 >> x2 >> x3;
	for(int i = 1; i <= 10; i++) {
		ans = min(ans, abs(x1 - i) + abs(x2 - i) + abs(x3 - i));
	}
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