#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	vector<int> x(n * m + 1), y(n * m + 1);
	vector<int> in_row(n), out_row(n);
	vector<int> in_col(m), out_col(m);
	auto print = [&](int dis) {
		cout << dis << '\n';
		vector<int> row(n), col(m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cout << v[i][j] << " \n"[j == m - 1];
				if(i != x[v[i][j]]) {
					in_row[i] += 1, out_row[x[v[i][j]]] += 1;
				}
				if(j != y[v[i][j]]) {
					in_col[j] += 1, out_col[y[v[i][j]]] += 1;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			cout << in_row[i] << " \n"[i == n - 1];
		}
		for(int i = 0; i < n; i++) {
			cout << out_row[i] << " \n"[i == n - 1];
		}
		for(int j = 0; j < m; j++) {
			cout << in_col[j] << " \n"[j == m - 1];
		}
		for(int j = 0; j < m; j++) {
			cout << out_col[j] << " \n"[j == m - 1];
		}
		cout << "----------\n";
	};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			v[i][j] = i * m + j + 1;
		}
		random_shuffle(v[i].begin(), v[i].end());
		for(int j = 0; j < m; j++) {
			x[v[i][j]] = i, y[v[i][j]] = j;
		}
	}
	auto dfs = [&](auto dfs, int u) -> void {
		if(u == 4) {
			return;
		}

		print(u);
		if(m != 1) {
			int c = rand() % m;
			int d;
			do {
				d = rand() % m;
			} while(d == c);
			for(int i = 0; i < n; i++) {
				swap(v[i][c], v[i][d]);
			}
			dfs(dfs, u + 1);
			for(int i = 0; i < n; i++) {
				swap(v[i][c], v[i][d]);
			}
		}


		if(n != 1) {
			int c = rand() % n, d;
			do {
				d = rand() % n;
			} while(d == c);
			swap(v[c], v[d]);
			dfs(dfs, u + 1);
			swap(v[c], v[d]);
		}
	};
	dfs(dfs, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}