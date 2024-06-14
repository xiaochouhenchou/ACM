#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 102, M = 2610;

int n, m, sum, v[N], t[N];
ll f[N][N][M];

void solve() {	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> v[i] >> t[i];
		sum += t[i];
	}
	// [-sum, sum] -> [0, sum * 2]

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k <= sum * 2; k++) {
				f[i][j][k] = -INF;
			}
		}
	}
	f[0][0][sum] = 0;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k <= sum * 2; k++) {
				f[i][j][k] = f[i - 1][j][k];	// 不选
				if(k >= t[i]) {	// 不操作放进第一个集合
					f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - t[i]] + v[i]);
				}
				if(k + t[i] <= sum * 2) {	// 不操作放进第二个集合
					f[i][j][k] = max(f[i][j][k], f[i - 1][j][k + t[i]] + v[i]);
				}
				if(j && k >= t[i] * 2) {	// 操作后放进第一个集合
					f[i][j][k] = max(f[i][j][k], 
						f[i - 1][j - 1][k - t[i] * 2] + v[i]);
				}
				if(j && k + t[i] * 2 <= sum * 2) {	// 操作后放进第二个集合
					f[i][j][k] = max(f[i][j][k], 
						f[i - 1][j - 1][k + t[i] * 2] + v[i]);
				}
			}
		}
	}

	ll ans = -INF;
	for(int j = 0; j <= m; j++) {
		ans = max(ans, f[n][j][sum]);
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