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
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), b(m + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int j = 1; j <= m; j++) {
		cin >> b[j];
	}
	for(int ans = 0; ans < (1 << 9); ans++) {
		int can = 1;
		for(int i = 1; i <= n; i++) {
			int ok = 0;
			for(int j = 1; j <= m; j++) {
				int tmp = (a[i] & b[j]);
				if((tmp | ans) == ans) {
					ok = 1;
					break;
				}
			}
			if(!ok) {
				can = 0;
				break;
			}
		}
		if(can) {
			cout << ans << '\n';
			return;
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