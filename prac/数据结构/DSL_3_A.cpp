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
	int n, s;
	cin >> n >> s;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = 0, ans = inf;
	for(int i = 1, j = 1; i <= n; i++) {
		while(j <= n && sum < s) {
			sum += a[j];
			j += 1;
		}
		if(sum >= s) {
			ans = min(ans, j - i);
		}
		sum -= a[i];
	}
	if(ans >= inf) ans = 0;
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