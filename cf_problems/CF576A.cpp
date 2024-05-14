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
	int n, cnt = 0;
	cin >> n;
	vector<int> vis(n + 1);
	for(int i = 1; i <= n; i++) {
		int x = i, ok = 0;
		for(int j = 2; j <= x / j; j++) {
			if(x % j == 0) {
				int p = 1;
				while(x % j == 0) x /= j, p *= j;
				if(!vis[p]) ok = 1;
			}
		}
		if(x > 1) {
			if(!vis[x]) ok = 1;
		}
		if(ok) {
			vis[i] = 1;
			cnt += 1;
		}
	}
	cout << cnt << '\n';
	for(int i = 1; i <= n; i++) {
		if(vis[i]) {
			cout << i << ' ';
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}