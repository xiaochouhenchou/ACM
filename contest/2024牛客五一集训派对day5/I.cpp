#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 20;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
string ch = "DLRU";
int dis[N][N][N][N];
int pre1[N][N][N][N];
int pre2[N][N][N][N];

void solve() {
	int n = 20;
	vector<vector<string>> mp(2, vector<string>(n));
	for(int i = 0; i < n; i++) {
		cin >> mp[0][i] >> mp[1][i];
	}
	auto can = [&](int i, int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < n 
		&& mp[i][x][y] != '#';
	};
	{
		queue<tuple<int, int, int, int>> q;
		q.emplace(n - 1, n - 1, n - 1, 0);
		memset(dis, -1, sizeof dis);
		memset(pre1, -1, sizeof pre1);
		memset(pre2, -1, sizeof pre2);
		dis[n - 1][n - 1][n - 1][0] = 0;
		while(sz(q)) {
			auto [x1, y1, x2, y2] = q.front();
			q.pop();

			int d = dis[x1][y1][x2][y2];
			for(int i = 0; i < 4; i++) {
				int a1 = x1 + dx[i];
				int b1 = y1 + dy[i];
				int a2 = x2 + dx[i];
				int b2 = y2 + dy[i];
				if(1 <= i && i <= 2) {
					a2 = x2 - dx[i];
					b2 = y2 - dy[i];
				}
				int t1 = can(0, a1, b1);
				int t2 = can(1, a2, b2);
				if(!t1 && !t2) continue;
				if(t1 && t2) {
					if(dis[a1][b1][a2][b2] == -1) {
						dis[a1][b1][a2][b2] = d + 1;
						pre1[a1][b1][a2][b2] = i;
						pre2[a1][b1][a2][b2] = i;
						q.emplace(a1, b1, a2, b2);
					}
				} else if(t1) {
					if(dis[a1][b1][x2][y2] == -1) {
						dis[a1][b1][x2][y2] = d + 1;
						pre1[a1][b1][x2][y2] = i;
						q.emplace(a1, b1, x2, y2);
					}
				} else {
					if(dis[x1][y1][a2][b2] == -1) {
						dis[x1][y1][a2][b2] = d + 1;
						pre2[x1][y1][a2][b2] = i;
						q.emplace(x1, y1, a2, b2);
					}
				}
			}
		}
	}

	cout << dis[0][n - 1][0][0] << '\n';
	string p = "";
	int x1 = 0, y1 = n - 1, x2 = 0, y2 = 0;
	while(true) {
		mp[0][x1][y1] = 'A';
		mp[1][x2][y2] = 'A';
		int i = pre1[x1][y1][x2][y2];
		int j = pre2[x1][y1][x2][y2];
		if(i == -1 && j == -1) break;
		if(~i && ~j) {
			p.push_back(ch[i]);
		} else if(~i) {
			p.push_back(ch[i]);
		} else {
			p.push_back(ch[j]);
		}

		if(~i) {
			x1 -= dx[i];
			y1 -= dy[i];
		}
		if(~j) {
			if(1 <= j && j <= 2) {
				x2 += dx[j];
				y2 += dy[j];
			} else {
				x2 -= dx[j];
				y2 -= dy[j];
			}
		}
	}
	reverse(p.begin(), p.end());
	cout << p << '\n';
	for(int i = 0; i < n; i++) {
		cout << mp[0][i] << ' ' << mp[1][i] << '\n';
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