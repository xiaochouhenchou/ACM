#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve() {
	int n, m, idx = 0;
	cin >> n >> m;
	vector<string> s(n + 1);
	vector<vector<int>> mp(n + 1, vector<int>(m + 1));
	vector<int> cnt(n * m + 1), vis(n * m + 1);
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
	}
	auto can = [&](int x, int y) {
		return x >= 1 && x <= n && y >= 1 && y <= m;
	};
	auto bfs = [&](int x, int y) {
		idx += 1;
		queue<PII> q;
		q.emplace(x, y);
		mp[x][y] = idx;
		cnt[idx] += 1;
		while(sz(q)) {
			auto [u, v] = q.front();
			q.pop();

			for(int i = 0; i < 4; i++) {
				int a = u + dx[i];
				int b = v + dy[i];
				if(!can(a, b) || mp[a][b] || s[a][b] == '.') continue;
				mp[a][b] = idx;
				cnt[idx] += 1;
				q.emplace(a, b);
			}
		}
	};

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(!mp[i][j] && s[i][j] == '#') {
				bfs(i, j);
				ans = max(ans, cnt[mp[i][j]]);
			}
		}
	}

	vector<int> tmp;
	for(int i = 1; i <= n; i++) {
		int res = 0;
		tmp.clear();
		for(int j = 1; j <= m; j++) {
			for(int k = 0; k < 2; k++) {
				int a = i + dx[k];
				int b = j + dy[k];
				if(!can(a, b) || !mp[a][b] || 
					vis[mp[a][b]]) continue;
				res += cnt[mp[a][b]];
				vis[mp[a][b]] = 1;
				tmp.push_back(mp[a][b]);
			}
		}
		for(int j = 1; j <= m; j++) {
			if(vis[mp[i][j]]) continue;
			res += 1;
		}
		ans = max(ans, res);

		for(int x : tmp) {
			vis[x] = 0;
		}
	}

	for(int j = 1; j <= m; j++) {
		int res = 0;
		tmp.clear();
		for(int i = 1; i <= n; i++) {
			for(int k = 2; k < 4; k++) {
				int a = i + dx[k];
				int b = j + dy[k];
				if(!can(a, b) || !mp[a][b] ||
					vis[mp[a][b]]) continue;
				res += cnt[mp[a][b]];
				vis[mp[a][b]] = 1;
				tmp.push_back(mp[a][b]);
			}
		}
		for(int i = 1; i <= n; i++) {
			if(vis[mp[i][j]]) continue;
			res += 1;
		}
		ans = max(ans, res);

		for(int x : tmp) {
			vis[x] = 0;
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