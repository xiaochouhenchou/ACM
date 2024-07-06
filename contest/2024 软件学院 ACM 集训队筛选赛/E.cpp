#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 5000 * 5000;

int n, m;
int minp[N + 1], minppow[N + 1];
ll g[N + 1];
vector<int> p;

void init() {
	for(int i = 2; i <= N; i++) {
		if(!minp[i]) {
			minp[i] = minppow[i] = i;
			p.push_back(i);
		}
		for(int j = 0; p[j] <= N / i; j++) {
			minp[p[j] * i] = p[j];
			minppow[p[j] * i] = p[j];
			if(i % p[j] == 0) {
				minppow[p[j] * i] = minppow[i] * p[j];
				break;
			}
		}
	}
}

void solve() {
	init();
	cin >> n;
	m = n * n;
	for(int i = 1, a; i <= n; i++) {
		cin >> a;
		for(int j = 1; j <= n; j++) {
			int x = a + (j - 1) * n;
			while(x > 1) {
				int t = minp[x];
				g[t] += 1;
				x /= minppow[x];
			}
		}
	}
	for(int i = m; i; i--) {
		for(int j = i + i; j <= m; j += i) {
			g[i] -= g[j];
		}
	}

	ll ans = 0;
	for(int x : b) {
		while(x > 1) {
			int t = minp[x];
			ans -= g[t]
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}