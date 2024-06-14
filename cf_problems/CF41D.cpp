#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 110, M = 11;

int a[N][N];
int f[N][N][M], pre[N][N][M];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	k += 1;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for(int j = 1; j <= m; j++) {
			a[i][j] = s[j - 1] - '0';
		}
	}

	memset(f, -0x3f, sizeof(f));
	for(int j = 1; j <= m; j++) {
		f[n][j][a[n][j] % k] = a[n][j];
	}
	for(int i = n - 1; i >= 1; i--) {
		for(int j = 1; j <= m; j++) {
			for(int r = 0; r < k; r++) {
				int pr = ((r - a[i][j]) % k + k) % k;
				if(j - 1 >= 1) {
					if(f[i][j][r] < f[i + 1][j - 1][pr] + a[i][j]) {
						f[i][j][r] = f[i + 1][j - 1][pr] + a[i][j];
						pre[i][j][r] = j - 1; 
					}
				}
				if(j + 1 <= m) {
					if(f[i][j][r] < f[i + 1][j + 1][pr] + a[i][j]) {
						f[i][j][r] = f[i + 1][j + 1][pr] + a[i][j];
						pre[i][j][r] = j + 1;
					}
				}
				// cout << i << ' ' << j << ' ' << r << ' ' 
				// << f[i][j][r] << '\n';
			}
		}
	}
	int ans = -inf, c = -1;
	for(int j = 1; j <= m; j++) {
		if(ans < f[1][j][0]) {
			ans = f[1][j][0];
			c = j;
		}
	}
	if(ans < 0) {
		cout << -1 << '\n';
	} else {
		int x = 1, r = 0;
		string str = "";
		while(true) {
			int pr = ((r - a[x][c]) % k + k) % k;
			int pc = pre[x][c][r];
			if(!pc) {
				break;
			}
			
			if(pc < c) {
				str.push_back('R');
			} else {
				str.push_back('L');
			}
			x += 1, c = pc, r = pr;
		}
		cout << ans << '\n';
		reverse(str.begin(), str.end());
		cout << c << '\n' << str << '\n';
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