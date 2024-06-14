#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <set>
#include <cstdio>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 10010;

int n, a[N];
double f[N], p[N], P;

void solve() {
	cin >> P >> n;
	int m = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> p[i];
		p[i] = 1.0 - p[i];
		m += a[i];
	}
	for(int i = 0; i <= m; i++) {
		f[i] = 0;
	}
	f[0] = 1.0;

	for(int i = 1; i <= n; i++) {
		for(int j = m; j >= a[i]; j--) {
			f[j] = max(f[j], f[j - a[i]] * p[i]);
		}
	}
	int ans = 0;
	for(int j = 0; j <= m; j++) {
		if(P - (1.0 - f[j]) > 0) {
			ans = j;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}