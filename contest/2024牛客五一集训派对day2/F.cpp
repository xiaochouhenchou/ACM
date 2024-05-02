#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<PII> p;
	for(int i = 0; i < n; i++) {
		int k, x;
		cin >> k;
		while(k--) {
			cin >> x;
			p.emplace_back(x, i);
		}
	}
	sort(p.begin(), p.end());
	vector<int> cnt(n);
	int c = 0, ans = inf;
	for(int i = 0, j = 0; i < sz(p); i++) {
		while(j < sz(p) && c < m) {
			if(++cnt[p[j].y] == 1) {
				c += 1;
			}
			j += 1;
		}
		if(c >= m) {
			ans = min(ans, p[j - 1].x - p[i].x);
		}
		if(--cnt[p[i].y] == 0) {
			c -= 1;
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
