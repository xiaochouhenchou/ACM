#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 200;

int f[N][N];

int dfs(int n, int m) {
	if(!m) {
		return n;
	}

	if(~f[n][m]) return f[n][m];

	int res = dfs(n, m - 1) | dfs(n + 1, m - 1);
	if(n > 0) res |= dfs(n - 1, m - 1);
	return f[n][m] = res;
}

void solve() {
	memset(f, -1, sizeof f);
	for(int n = 0; n <= 32; n++) {
		for(int m = 0; m <= 5; m++) {
			cout << n << ' ' << m << ' ' << dfs(n, m) << '\n';
		}
		cout << "-----------------\n";
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