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
	int n, q;
	string s;
	cin >> n >> q >> s;
	s = " " + s;
	vector<vector<int>> p(n + 1, vector<int>(3));
	for(int i = 1; i <= n; i++) {
		p[i][0] = p[i - 1][0] + (s[i] == 'r');
		p[i][1] = p[i - 1][1] + (s[i] == 'e');
		p[i][2] = p[i - 1][2] + (s[i] == 'd');
	}
	while(q--) {
		int l, r;
		cin >> l >> r;
		int m = r - l + 1;
		if(m < 3) {
			cout << 0 << '\n';
			continue;
		}
		
		int x = m / 3, ans = 0;
		if(m % 3 == 0) {
			int len1 = x, len2 = x, len3 = x;
			int l1 = l - 1, r1 = l1 + len1;
			int l2 = r1, r2 = l2 + len2;
			int l3 = r2, r3 = l3 + len3;
			ans += max(len1 - (p[r1][0] - p[l1][0]), 0);
			ans += max(len2 - (p[r2][1] - p[l2][1]), 0);
			ans += max(len3 - (p[r3][2] - p[l3][2]), 0);
		} else if(m % 3 == 1) {
			ans = inf;
			for(int i = 1; i <= 3; i++) {
				int res = 0;
				int len1 = x + (i == 1);
				int len2 = x + (i == 2);
				int len3 = x + (i == 3);
				int l1 = l - 1, r1 = l1 + len1;
				int l2 = r1, r2 = l2 + len2;
				int l3 = r2, r3 = l3 + len3;	
				res += max(len1 - (p[r1][0] - p[l1][0]), 0);
				res += max(len2 - (p[r2][1] - p[l2][1]), 0);
				res += max(len3 - (p[r3][2] - p[l3][2]), 0);					
				ans = min(ans, res);
			}
		} else {
			ans = inf;
			for(int i = 1; i <= 3; i++) {
				for(int j = i + 1; j <= 3; j++) {
					int res = 0;
					int len1 = x + (i == 1) + (j == 1);
					int len2 = x + (i == 2) + (j == 2);
					int len3 = x + (i == 3) + (j == 3);
					int l1 = l - 1, r1 = l1 + len1;
					int l2 = r1, r2 = l2 + len2;
					int l3 = r2, r3 = l3 + len3;	
					res += max(len1 - (p[r1][0] - p[l1][0]), 0);
					res += max(len2 - (p[r2][1] - p[l2][1]), 0);
					res += max(len3 - (p[r3][2] - p[l3][2]), 0);							
					ans = min(ans, res);					
				}
			}
		}
		cout << ans << '\n';
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