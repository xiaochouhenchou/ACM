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
	int n, cnt = 0, sum = 0;
	cin >> n;
	for(int i = 0, x; i < n; i++) {
		cin >> x;
		cnt += (x < 0);
		sum += abs(x);
	}
	if(cnt >= n) {
		cout << "inf\n";
		return;
	}
	n -= cnt;
	int g = __gcd(sum, n);
	cout << sum / g << "/" << n / g << '\n';
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