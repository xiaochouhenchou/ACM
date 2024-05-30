#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// 贪心地一层一层放节点
void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), c(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int h = 0;
	c[h] = 1;
	for(int i = 2; i <= n; ) {
		int j = i + 1, cost = 1;
		h += 1;
		while(j <= n) {
			if(a[j] > a[j - 1]) j += 1;
			else if(cost == c[h - 1]) break;
			else {
				cost += 1;
				j += 1;
			}
		}
		// cout << i << ' ' << j << '\n';
		c[h] = j - i;
		i = j;
	}
	cout << h << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}