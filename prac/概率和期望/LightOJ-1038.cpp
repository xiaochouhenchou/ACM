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
const int N = 100000;

double f[N + 1];
vector<int> d[N + 1];

void init() {
	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N; j += i) {
			d[j].push_back(i);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	f[1] = 0.0;
	for(int x : d[n]) {
		if(x == 1) continue;
		double res = 0;
		for(int y : d[x]) {
			if(y != x)
				res += f[y];
		}
		res += sz(d[x]);
		if(sz(d[x]) > 1) {
			res /= 1.0 * (sz(d[x]) - 1);
		}
		f[x] = res;
	}
	cout << fixed << setprecision(8) << f[n] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}