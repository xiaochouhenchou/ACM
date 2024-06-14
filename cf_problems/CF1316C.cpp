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
	int n, m, p;
	cin >> n >> m >> p;
	int l = -1, r = -1;
	for(int i = 0, a; i < n; i++) {
		cin >> a;
		if(a % p != 0) {
			l = i;
		}
	}
	for(int i = 0, b; i < m; i++) {
		cin >> b;
		if(b % p != 0) {
			r = i;
		}
	}
	cout << (l + r) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}