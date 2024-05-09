#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

/*
	思路： 洛谷P3400
*/
void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n + 1);
	vector<vector<int>> up(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
	}
	// 预处理 up 数组
	for(int j = 1; j <= m; j++) {
		for(int i = 1; i <= n; i++) {
			if(s[i][j] == '*') up[i][j] = i;
			else up[i][j] = up[i - 1][j];
		}
	}
	vector<ll> res(m + 1), stk;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		stk.clear();
		up[i][0] = inf;
		stk.push_back(0);
		fill(res.begin(), res.end(), 0);
		for(int j = 1; j <= m; j++) {
			while(sz(stk) && up[i][stk.back()] < up[i][j]) {
				stk.pop_back();
			}
			res[j] = res[stk.back()] + 1ll * (i - up[i][j]) 
					* (j - stk.back());
			stk.push_back(j);
			ans += res[j];
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