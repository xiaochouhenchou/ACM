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
		gcd(a, b) = gcd(a, b - a)
		-> gcd(a[i] + b[j], a[i + 1] + b[j], ...)
		 = gcd(a[i] + b[j], a[i + 1] - a[i], a[i + 2] - a[i + 1], ...)
		因此维护 g = gcd(a[2] - a[1], a[3] - a[2], ...) 再枚举 j 计算答案即可。
		注意处理负数。
*/
void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n + 1), b(m + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	ll g = 0;
	for(int i = 2; i <= n; i++) {
		g = abs(__gcd(a[i] - a[i - 1], g));
	}
	for(int i = 1; i <= m; i++) {
		cout << abs(__gcd(a[1] + b[i], g)) << " \n"[i == m];
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