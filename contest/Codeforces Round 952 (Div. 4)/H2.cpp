#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n + 2);
	// 和第 i 行相邻的（经过 i - 1, i, i + 1行）的连通块的大小和
	vector<int> R(n + 2);		
	// 和第 j 列相邻的（经过 j - 1, j, j + 1列）的连通块的大小和
	vector<int> C(m + 2);		
	// 第 i 行和第 j 列操作之后的贡献 ('.' -> '#' 的数量)
	vector<int> F1(n + 2);
	vector<int> F2(m + 2);	
	// R[i] 和 C[j] 重复计算的部分
	vector<vector<int>> B(n + 2, vector<int>(m + 2));
	vector<vector<int>> vis(n + 2, vector<int>(m + 2));
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
	}
	auto can = [&](int x, int y) {
		return x >= 1 && x <= n && y >= 1 && y <= m;
	};
	auto dfs = [&](auto dfs, int x, int y, int &rmin, int &rmax, 
		int &cmin, int &cmax) -> int {
		int res = 1;
		vis[x][y] = 1;
		rmin = min(rmin, x);
		rmax = max(rmax, x);
		cmin = min(cmin, y);
		cmax = max(cmax, y);
		for(int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			if(!can(a, b) || vis[a][b] || s[a][b] == '.') continue;
			res += dfs(dfs, a, b, rmin, rmax, cmin, cmax);
		}
		return res;
	};
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(!vis[i][j] && s[i][j] != '.') {
				int rmin = inf, rmax = -inf;
				int cmin = inf, cmax = -inf;
				int s = dfs(dfs, i, j, rmin, rmax, cmin, cmax);
				int a = max(1, rmin - 1);
				int b = min(n, rmax + 1);
				int c = max(1, cmin - 1);
				int d = min(m, cmax + 1);
				R[a] += s;
				R[b + 1] -= s;
				C[c] += s;
				C[d + 1] -= s;

				B[a][c] += s;	B[b + 1][d + 1] += s;
				B[a][d + 1] -= s;	B[b + 1][c] -= s;
			}
			if(s[i][j] == '.') {
				F1[i] += 1;
				F2[j] += 1;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		R[i] += R[i - 1];
	}
	for(int j = 1; j <= m; j++) {
		C[j] += C[j - 1];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			B[i][j] += B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ans = max(ans, F1[i] + F2[j] - (s[i][j] == '.') 
				+ R[i] + C[j] - B[i][j]);
		}
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