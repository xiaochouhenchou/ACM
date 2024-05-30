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
	int m, n;
	cin >> m >> n;
	vector<int> d(n + 1);
	vector f(m + 1, inf);
	f[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> d[i];
	}	
	for(int j = 0; j <= m; j++) {
		for(int i = 1; i <= n; i++) {
			if(d[i] <= j) {
				f[j] = min(f[j], f[j - d[i]] + 1);
			}
		}
	}
	cout << f[m] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}