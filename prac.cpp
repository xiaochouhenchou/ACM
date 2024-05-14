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
	ll sum = s;
	int maxv = 0, l = -1, r = -1;
	for(int j = 1, i = 1; j <= n; j++) {
		sum += a[j];
		while(sum < 0) {
			sum -= a[i];
			i += 1;
		}
		if(maxv < j - i + 1) {
			maxv = j - i + 1;
			l = i, r = j;
		}
	}
	if(l == -1) cout << -1 << '\n';
	else cout << l << ' ' << r << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}