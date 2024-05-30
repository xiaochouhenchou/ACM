#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

int n, m, k;

void solve() {
	cin >> n >> m >> k;
	vector<int> sx(k + 1), sy(k + 1);
	vector<int> fx(k + 1), fy(k + 1);
	for(int i = 1; i <= k; i++) {
		cin >> sx[i] >> sy[i];
	}
	for(int i = 1; i <= k; i++) {
		cin >> fx[i] >> fy[i];
	}
	string ans = string(n - 1, 'U') + string(m - 1, 'L');
	for(int i = 1; i <= n; i++) {
		if(i & 1) ans += string(m - 1, 'R');
		else ans += string(m - 1, 'L');
		if(i != n) ans += "D";
	}
	cout << sz(ans) << '\n' << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}