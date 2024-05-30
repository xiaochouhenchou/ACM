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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(n, vector<int>(n));
	vector<int> r(n), c(n);
	auto work = [&](int x, int y) {
		for(int i = 0; i < n && k; i++) {
			a[x][y] = 1;
			k -= 1;
			x = (x + 1) % n;
			y = (y - 1 + n) % n;
		}
	};
	work(0, n - 1);	
	for(int y = n - 2; y >= 0 && k; y--) {
		work(0, y);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			r[i] += a[i][j];
		}
	}
	for(int j = 0; j < n; j++) {
		for(int i = 0; i < n; i++) {
			c[j] += a[i][j];
		}
	}
	int dx = *max_element(r.begin(), r.end()) 
	- *min_element(r.begin(), r.end());
	int dy = *max_element(c.begin(), c.end()) 
	- *min_element(c.begin(), c.end());
	cout << dx * dx + dy * dy << '\n';
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << a[i][j];
		}
		cout << '\n';
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