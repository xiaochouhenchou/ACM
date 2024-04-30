#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const double eps = 1e-8;
const int mod = 1e9 + 9;

void solve() {
	int n;
	cin >> n;
	vector<string> s(n + 1);
	vector<int> pre(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		pre[i] = pre[i - 1] + (s[i] == "byl");
	}
	int ans = 0;
	for(int r = 1; r <= n; r++) {
		for(int l = 1; l <= r; l++) {
			int cnt = pre[r] - pre[l - 1];
			if(cnt > r - l + 1 - cnt) {
				ans += 1;
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
	while(t--) {
		solve();
	}
	return 0;
}
