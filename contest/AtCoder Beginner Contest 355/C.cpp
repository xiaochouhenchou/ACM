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
	int n, t;
	cin >> n >> t;
	map<int, int> row, col, dg, rdg;
	vector<int> a(t + 1);
	for(int i = 1; i <= t; i++) {
		cin >> a[i];
		a[i] -= 1;
	}
	for(int i = 1; i <= t; i++) {
		int x = a[i] / n, y = a[i] % n;
		if(++row[x] == n) {
			cout << i << '\n';
			return;
		}
		if(++col[y] == n) {
			cout << i << '\n';
			return;
		}
		if(++dg[x - y] == n) {
			cout << i << '\n';
			return;
		}
		if(++rdg[x + y] == n) {
			cout << i << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}