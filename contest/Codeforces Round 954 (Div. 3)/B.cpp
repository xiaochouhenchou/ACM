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
	vector<vector<int>> a(n, vector<int>(m));
	for(auto &v : a) {
		for(auto &x : v) {
			cin >> x;
		}
	}
	auto can = [&](int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int ok = 1, maxv = -inf;
			for(int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if(!can(x, y)) continue;
				if(a[i][j] <= a[x][y]) {
					ok = 0;
				}
				maxv = max(maxv, a[x][y]);
			}
			if(ok) {
				a[i][j] = maxv;
			}
			cout << a[i][j] << " \n"[j == m - 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}