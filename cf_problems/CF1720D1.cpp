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
	int n;
	cin >> n;
	vector<int> a(n), f(n, 1);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	// a[i] <= 200, i ^ a[i] >= i - a[i]
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int idx = -1;
		for(int j = max(i - 255, 0); j < i; j++) {
			if((a[j] ^ i) < (a[i] ^ j)) {
				f[i] = max(f[i], f[j] + 1);
			}
		}
		ans = max(ans, f[i]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}