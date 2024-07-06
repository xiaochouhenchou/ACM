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
	vector<int> state(n);
	string s;
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < m; j++) {
			if(s[j] == 'o') {
				state[i] |= 1 << j;
			}
		}
	}
	int ans = inf;
	for(int i = 0; i < (1 << n); i++) {
		int res = 0, cnt = 0;
		for(int j = 0; j < n; j++) {
			if(i >> j & 1) {
				res |= state[j];
				cnt += 1;
			}
		}
		if(__builtin_popcount(res) == m) {
			ans = min(ans, cnt);
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