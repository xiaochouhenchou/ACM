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
	int x = 1, y = 1, a, b, n;
	cin >> b >> a >> n;
	for(int i = 3; i <= n; i++) {
		int z = (a * x % 7 + b * y % 7) % 7;
		x = y, y = z;
	}
	cout << y << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}