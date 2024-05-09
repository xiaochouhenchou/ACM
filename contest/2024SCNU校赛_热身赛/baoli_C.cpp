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
	vector<string> s(n + 1);
	vector<vector<int>> p(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
		for(int j = 1; j <= m; j++) {
			p[i][j] = p[i - 1][j] + p[i][j - 1] + 
			(s[i][j] == '*') - p[i - 1][j - 1];
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int u = i; u <= n; u++) {
				for(int v = j; v <= m; v++) {
					int sum = p[u][v] - p[u][j - 1] - p[i - 1][v]
					 + p[i - 1][j - 1];
					if(!sum) {
						ans += 1;
					}
				}
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