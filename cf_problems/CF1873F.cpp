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
	vector<int> a(n + 1), h(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; ) {
		int j = i + 1;
		while(j <= n && h[j - 1] % h[j] == 0) j += 1;
		ll sum = 0;
		int l = i, r = i;
		while(r < j) {
			sum += a[r];
			r += 1;
			while(sum > k) {
				sum -= a[l];
				l += 1;
			}
			ans = max(ans, r - l);
		}
		i = j;
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