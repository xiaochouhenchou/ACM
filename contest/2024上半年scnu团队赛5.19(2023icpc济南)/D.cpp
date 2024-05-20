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
	思路: ra - la + 1 >= 10 或 rb - lb + 1 >= 10 答案即为 9，
		 因为个位上出现了 [0, 9] 十个数。否则暴力枚举判断即可。
*/
void solve() {
	int la, ra, lb, rb;
	cin >> la >> ra >> lb >> rb;
	if(ra - la >= 9 || rb - lb >= 9) {
		cout << 9 << '\n';
	} else {
		int ans = 0;
		for(int i = la; i <= ra; i++) {
			for(int j = lb; j <= rb; j++) {
				string s = to_string(i + j);
				ans = max(ans, *max_element(s.begin(), s.end()) - '0');
			}
		}
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}