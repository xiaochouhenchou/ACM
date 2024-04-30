#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const int mod = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> c(n + 1), cnt(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		cnt[c[i]] += 1;
	}
	int mx1 = 0, mx2 = 0;
	for(int i = 1; i <= n; i++) {
		if(mx1 <= cnt[i]) {
			mx2 = mx1;
			mx1 = cnt[i];
		} else if(mx2 < cnt[i]) {
			mx2 = cnt[i];
		}
	}
	int ans = (mx1 | mx2 | ((1 << (__lg(mx1 & mx2) + 1)) - 1));
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;	
	while(t--) {
		solve();
	}
	return 0;
}