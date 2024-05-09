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
	vector<vector<int>> up(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for(int j = 1; j <= m; j++) {
		for(int i = 1; i <= n; i++) {
			if(!a[i][j]) up[i][j] = i;
			else up[i][j] = up[i - 1][j];
		}
	}
	vector<int> stk;
	vector<ll> res(m + 1);
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		stk.clear();
		fill(res.begin(), res.end(), 0);
		for(int j = 1; j <= m; j++) {
			while(sz(stk) && up[i][stk.back()] < up[i][j]) {
				stk.pop_back();
			}
			int l = (sz(stk) ? stk.back() : 0);
			res[j] = 1ll * (j - l) * (i - up[i][j]);
			if(sz(stk)) res[j] += res[stk.back()];
			ans += res[j];
			stk.push_back(j);
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