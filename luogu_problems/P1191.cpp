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
	int n;
	cin >> n;
	vector<string> s(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
	}	

	vector<ll> up(n + 1), res(n + 1), stk;
	up[0] = inf;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		fill(res.begin(), res.end(), 0);
		stk.clear();
		stk.push_back(0);
		
		for(int j = 1; j <= n; j++) {
			if(s[i][j] == 'B') up[j] = i;
			while(sz(stk) && up[stk.back()] < up[j]) {
				stk.pop_back();
			}
			res[j] = res[stk.back()] + (i - up[j]) * (j - stk.back());
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