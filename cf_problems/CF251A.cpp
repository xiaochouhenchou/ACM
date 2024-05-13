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
	思路: 双指针，假如所求三元组 (i, j, k)，那么两个指针分别指向 i、 k，
		 当 a[k] - a[i] <= d 的时候，i、 j 的选择有 c(j - i, 2) 种。
		 把所有 k 的方案数加起来即可。
*/
void solve() {
	int n, d;
	cin >> n >> d;
	vector<int> x(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	ll res = 0;
	for(int j = 1, i = 1; j <= n; j++) {
		while(i <= n && x[j] - x[i] > d) i += 1;
		ll len = max(j - i, 0);
		res += len * (len - 1) / 2;
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}