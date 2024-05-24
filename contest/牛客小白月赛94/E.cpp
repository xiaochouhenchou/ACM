#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 2010, M = 11;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n), w(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i] >> w[i];
	}
	int ans = 0;
	for(int i = 29; i >= 0; i--) {
		int V = (1 << 30) - 1;
		int t = ans | (1 << i);
		for(int j = 0; j < n; j++) {
			if((w[j] & t) == t) {
				V &= v[j];
			}
		}
		if(V <= m) {
			ans = t;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}