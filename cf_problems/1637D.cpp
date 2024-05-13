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
	思路: 
		cost = sum((a[i] + a[j])^2)
			 = sum((a[i]^2 + 2 * a[i] * a[j] + a[j]^2))
			 = (n - 1) * a[i]^2 + sum(a[i] * (sum(a[i]) - a[i]))
			 = (n - 1) * a[i]^2 - a[i]^2 + sum(a[i])^2
			 = (n - 2) * a[i]^2 + sum(a[i])^2
		res = (n - 2) * a[i]^2 + (n - 2) * b[i]^2 
				+ sum(a[i])^2 + sum(b[i])^2
		问题转化成让 sum(a[i])^2 + sum(b[i])^2 最小。
		
		f[i][j] 表示 a 中前 i 个数和能否为 j，
		f[i][j] = f[i - 1][j - a[i]] | f[i - 1][j - b[i]]。
		最后枚举 f[n][j] 计算答案的最小值。
*/

void solve() {
	int n;
	cin >> n;
	ll constant = 0, sum = 0;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		constant += a[i] * a[i];
		sum += a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		constant += b[i] * b[i];
		sum += b[i];
	}
	constant *= (n - 2);

	if(n == 1) {
		cout << 0 << '\n';
		return;
	}

	vector<vector<int>> f(n + 1, vector<int>(10001));
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 10000; j++) {
			if(j >= a[i])
				f[i][j] |= f[i - 1][j - a[i]];
			if(j >= b[i])
				f[i][j] |= f[i - 1][j - b[i]];
		}
	}
	ll ans = INF;
	for(ll j = 0; j <= 10000; j++) {
		if(f[n][j]) {
			ans = min(ans, constant + j * j + (sum - j) * (sum - j));
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