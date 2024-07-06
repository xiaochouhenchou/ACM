#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 50;

int n, m, K, x, y, A[N + 1][N + 1];
ll f[N * N + 1][N + 1][N + 1];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
	cin >> n >> m >> K >> x >> y;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> A[i][j];
		}
	}
	for(int i = 0; i <= min(n * m, K); i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= m; k++) {
				f[i][j][k] = -INF * 5;
			}
		}
	}	

	{
		queue<tuple<int, int, int>> q;
		q.emplace(0, x, y);
		f[0][x][y] = 0;
		while(sz(q)) {
			auto [s, a, b] = q.front();
			q.pop();

			if(s + 1 > min(n * m, K)) continue;

			for(int i = 0; i < 4; i++) {
				int c = a + dx[i];
				int d = b + dy[i];
				if(c < 1 || c > n || d < 1 || d > m || 
					f[s + 1][c][d] >= f[s][a][b] + A[c][d]) continue;
				f[s + 1][c][d] = f[s][a][b] + A[c][d];
				q.emplace(s + 1, c, d);
			}
		}
	}

	ll ans = -INF * 5;
	for(int i = 0; i <= min(n * m, K); i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= m; k++) {
				// cout << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << '\n';
				ans = max(ans, f[i][j][k] + 1ll * (K - i) * A[j][k]);
			}
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