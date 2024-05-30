#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1000;

int n, m;
int f[11][N + 2][N + 2];
int s[11][N + 2][N + 2];

void solve() {
	cin >> n >> m;
	for(int j = 1; j <= n; j++) {
		for(int k = j; k <= n; k++) {
			f[1][j][k] = 1;
		}
	}
	for(int j = 1; j <= n; j++) {
		for(int k = n; k >= j; k--) {
			s[1][j][k] += (s[1][j][k + 1] + f[1][j][k]) % mod;
			s[1][j][k] %= mod;
		}
	}
	for(int j = 1; j <= n; j++) {
		for(int k = j; k <= n; k++) {
			s[1][j][k] += s[1][j - 1][k];
			s[1][j][k] %= mod;
		}
	}
	for(int i = 2; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = j; k <= n; k++) {
				f[i][j][k] += s[i - 1][j][k];
				f[i][j][k] %= mod;
			}
		}
		for(int j = 1; j <= n; j++) {
			for(int k = n; k >= j; k--) {
				s[i][j][k] += (s[i][j][k + 1] + f[i][j][k]) % mod;
				s[i][j][k] %= mod;
			}
		}
		for(int j = 1; j <= n; j++) {
			for(int k = j; k <= n; k++) {
				s[i][j][k] += s[i][j - 1][k];
				s[i][j][k] %= mod;
			}
		}		
	}
	int ans = 0;
	for(int j = 1; j <= n; j++) {
		for(int k = j; k <= n; k++) {
			ans += f[m][j][k];
			ans %= mod;
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