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
	vector<int> t(n + 1), a(n + 1), b(n + 1);
	vector<int> p1{0}, p2{0}, p3{0};
	for(int i = 1; i <= n; i++) {
		cin >> t[i] >> a[i] >> b[i];
		if(a[i] && b[i]) {
			p1.push_back(t[i]);
		}
		if(a[i] && !b[i]) {
			p2.push_back(t[i]);
		}
		if(!a[i] && b[i]) {
			p3.push_back(t[i]);
		}
	}
	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());
	sort(p3.begin(), p3.end());
	for(int i = 1; i < sz(p1); i++) {
		p1[i] += p1[i - 1];
	}
	for(int i = 1; i < sz(p2); i++) {
		p2[i] += p2[i - 1];
	}
	for(int i = 1; i < sz(p3); i++) {
		p3[i] += p3[i - 1];
	}
	int ans = inf * 2;
	for(int x = 0; x <= sz(p1) - 1; x++) {
		int cnt = max(k - x, 0);
		if(cnt >= sz(p2) || cnt >= sz(p3)) {
			continue;
		}
		int res = p1[x] + p2[cnt] + p3[cnt];
		ans = min(ans, res);
	}
	if(ans >= inf * 2) ans = -1;
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