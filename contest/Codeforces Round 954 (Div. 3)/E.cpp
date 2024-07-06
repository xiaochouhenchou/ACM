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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto &x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());

	int cnt = 0;
	map<int, vector<int>> mp;
	for(auto &x : a) {
		mp[x % k].push_back(x);
	}
	for(auto &[r, v] : mp) {
		cnt += sz(v) % 2;
	}
	if(cnt > n % 2) {
		cout << -1 << '\n';
		return;	
	}

	ll ans = 0;
	for(auto &[r, v] : mp) {
		if(sz(v) % 2 == 0) {
			ll res = 0;
			for(int i = 0; i < sz(v); i++) {
				if(i % 2 == 0) {
					res -= v[i];
				} else {
					res += v[i];
				}
			}
			ans += res / k;
		} else {
			int m = sz(v);
			vector<vector<ll>> pre(m + 2, vector<ll>(2));
			vector<vector<ll>> suf(m + 2, vector<ll>(2));
			for(int i = 0; i < m; i++) {
				pre[i + 1][0] = pre[i][0] + (i % 2 == 1 ? v[i] : 0);
				pre[i + 1][1] = pre[i][1] + (i % 2 == 0 ? v[i] : 0);
			}
			for(int i = m; i; i--) {
				suf[i][0] = suf[i + 1][0] + (i % 2 == 0 ? v[i - 1] : 0);
				suf[i][1] = suf[i + 1][1] + (i % 2 == 1 ? v[i - 1] : 0);
			}
			ll res = INF;
			for(int i = 1; i <= m; i++) {
				res = min(res, pre[i - 1][0] - pre[i - 1][1] + suf[i + 1][1] - 
					suf[i + 1][0]);
			}
			ans += res / k;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}