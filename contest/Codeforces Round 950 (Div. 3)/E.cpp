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
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	vector<int> x(n * m + 1), y(n * m + 1);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 1, b; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> b;
			x[b] = i, y[b] = j;
		}
	}	
	int ok = 1;
	for(int i = 1; i <= n; i++) {
		int last = x[a[i][1]];
		for(int j = 2; j <= m; j++) {
			if(x[a[i][j]] != last) {
				ok = 0;
				break;
			}
			last = x[a[i][j]];
		}
	}
	for(int j = 1; j <= m; j++) {
		int last = y[a[1][j]];
		for(int i = 2; i <= n; i++) {
			if(y[a[i][j]] != last) {
				ok = 0;
				break;
			}
			last = y[a[i][j]];
		}
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}