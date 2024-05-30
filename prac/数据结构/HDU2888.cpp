#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 301;

/*
	二维 rmq: f[i][j][k][l] 表示以 (i, j) 为左上角，以 
	(i + 2^k - 1, j + 2^l - 1) 为右下角的矩阵的最大值。
	考虑转移，把这个矩阵分成四个部分： 
	(i, j) - (i + 2^(k - 1) - 1, j + 2^(l - 1) - 1)、
	(i, j + 2^(l - 1)) - (i + 2^(k - 1) - 1, j + 2^l - 1)、
	(i + 2^(k - 1), j) - (i + 2^k - 1, j + 2^(l - 1) - 1)、
	(i + 2^(k - 1), j + 2^(l - 1)) - (i + 2^k - 1, j + 2^l - 1)
*/

int f[N][N][9][9], lg[N];

void solve() {
	int n, m;
	for(int i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;
	while(cin >> n >> m) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> f[i][j][0][0];
			}
		}

		for(int k = 1; k < 9; k++) {
			for(int i = 1; i + (1 << k) - 1 <= n; i++) {
				for(int j = 1; j <= m; j++) {	
					int v = 0;
					int di = 1 << (k - 1);
					v = max(v, f[i][j][k - 1][0]);
					v = max(v, f[i + di][j][k - 1][0]);	
					f[i][j][k][0] = v;												
				}
			}
		}
		for(int l = 1; l < 9; l++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j + (1 << l) - 1 <= m; j++) {	
					int v = 0;
					int dj = 1 << (l - 1);
					v = max(v, f[i][j][0][l - 1]);
					v = max(v, f[i][j + dj][0][l - 1]);		
					f[i][j][0][l] = v;												
				}
			}
		}
		for(int k = 1; k < 9; k++) {
			for(int l = 1; l < 9; l++) {
				for(int i = 1; i + (1 << k) - 1 <= n; i++) {
					for(int j = 1; j + (1 << l) - 1 <= m; j++) {
						int v = 0;
						int di = 1 << (k - 1);
						int dj = 1 << (l - 1);
						v = max(v, f[i][j][k - 1][l - 1]);
						v = max(v, f[i][j + dj][k - 1][l - 1]);
						v = max(v, f[i + di][j][k - 1][l - 1]);
						v = max(v, f[i + di][j + dj][k - 1][l - 1]);
						f[i][j][k][l] = v;
					}
				}
			}				
		}		

		auto query = [&](int a, int b, int c, int d) {
			int kx = lg[c - a + 1];
			int ky = lg[d - b + 1];
			int lenx = 1 << kx;
			int leny = 1 << ky;
			int res = 0;
			res = max(res, f[a][b][kx][ky]);
			res = max(res, f[a][d - leny + 1][kx][ky]);
			res = max(res, f[c - lenx + 1][b][kx][ky]);
			res = max(res, f[c - lenx + 1][d - leny + 1][kx][ky]);
			return res;
		};
		int q;
		cin >> q;
		while(q--) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			int maxv = query(a, b, c, d);
			if(maxv == f[a][b][0][0] || maxv == f[a][d][0][0] ||
				maxv == f[c][b][0][0] || maxv == f[c][d][0][0]) {
				cout << maxv << " yes\n";
			} else {
				cout << maxv << " no\n";
			}
		}
	}
}

int main() {
	// freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}