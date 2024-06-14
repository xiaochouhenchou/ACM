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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<double> f(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = n; i >= 1; i--) {
		double tmp = 0;
		int cnt = 0;
		for(int j = 1; j <= 6 && i + j <= n; j++) {
			tmp += f[i + j];
			cnt += 1;
		}
		f[i] = a[i];
		if(cnt) {
			f[i] += tmp / (1.0 * cnt);
		}
	}
	cout << fixed << setprecision(8) << f[1] << '\n';
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