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
	int ans = n;
	for(int i = 2; i <= n / i; i++) {
		if(n % i == 0) {
			while(n % i == 0) n /= i;
			ans = ans / i * (i - 1);
		}
	}
	if(n > 1) ans = ans / n * (n - 1);
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