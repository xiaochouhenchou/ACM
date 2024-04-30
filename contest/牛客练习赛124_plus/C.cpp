#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 4e14;
const int mod = 1e9 + 7;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> l(n + 1), r(n + 1);
	map<int, vector<int>> mp;
	for(int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		mp[r[i]].push_back(l[i]);
	}
	priority_queue<int, vector<int>, greater<int>> q;
	LL ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++) {
		for(auto &x : it->y) {
			q.push(x);
			if(sz(q) > k) q.pop();
		}
		if(sz(q) >= k) {
			LL mul = 1;
			if(next(it) != mp.end()) {
				LL next_r = next(it)->x;
				mul = next_r - it->x;
			}
			ans += mul * q.top();
		}
	}
	ans += 1ll * (m - mp.rbegin()->x) * q.top();
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;	
	while(t--) {
		solve();
	}
	return 0;
}
