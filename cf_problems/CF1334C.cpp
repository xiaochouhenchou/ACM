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
	vector<ll> a(n), b(n), con(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	ll sum = 0, ans = INF;
	for(int i = 0; i < n; i++) {
		con[i] = max(a[i] - b[(i - 1 + n) % n], 0ll);
		sum += con[i];
	}
	for(int i = 0; i < n; i++) {
		ans = min(ans, a[i] + sum - con[i]);
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