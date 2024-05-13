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
	思路: a[i] / b[i] 这个分数可以被分母为 b[i] 的倍数的分数表示，
		 那么分母一定包含了 b[i] 的所有质因子。所有质因子的乘积即为
		 答案。
*/
void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	map<int, int> mp;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		int x = b[i];
		for(int j = 2; j <= x / j; j++) {
			if(x % j == 0) {
				while(x % j == 0) x /= j;
				mp[j] += 1;
			}
		}
		if(x > 1) mp[x] += 1;
	}
	ll ans = 1;
	for(auto [x, c] : mp) {
		ans *= x;
	}
	// cout << ans << '\n';
	string s = "";
	while(ans) {
		ll r = ans % 16;
		if(r < 10) s.push_back(r + '0');
		else s.push_back(r - 10 + 'A');
		ans /= 16;
	}
	reverse(s.begin(), s.end());
	cout << s << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}