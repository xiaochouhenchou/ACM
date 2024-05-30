#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1005;

int diff[N][N];

void solve() {
	int n;
	cin >> n;
	while(n--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a += 1, b += 1, c += 1, d += 1;
		diff[a][b] += 1;	diff[c + 1][d + 1] -= 1;
		diff[a][d + 1] -= 1;	diff[c + 1][b] -= 1;
	}
	n = 1001;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			diff[i][j] += diff[i - 1][j] + diff[i][j - 1] -
						diff[i - 1][j - 1];
			ans = max(ans, diff[i][j]);
		}
	}
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