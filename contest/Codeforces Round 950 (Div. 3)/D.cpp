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
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1), s(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n - 1; i++) {
		b[i] = __gcd(a[i], a[i + 1]);
		// cout << b[i] << " \n"[i == n - 1];
		s[i] = s[i - 1] + (b[i] >= b[i - 1]);
	}
	int ok = (s[n - 1] - s[2] >= n - 3) || (s[n - 2] >= n - 2);
	// cout << ok << '\n';
	for(int i = 2; i <= n - 1; i++) {
		int t = __gcd(a[i - 1], a[i + 1]);
		int res = 1;
		if(i - 2 >= 1) {
			res &= (s[i - 2] >= i - 2);
			res &= b[i - 2] <= t;
		}
		if(i + 1 <= n - 1) {
			res &= (s[n - 1] - s[i + 1] >= n - i - 2);
			res &= t <= b[i + 1];
		}
		// cout << i << ' ' << res << '\n';
		ok |= res;
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}