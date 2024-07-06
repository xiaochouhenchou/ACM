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
	vector<ll> a(n + 1), s(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	priority_queue<ll, vector<ll>, greater<ll>> q;
	for(int i = 1; i < n; i++) {
		q.push(s[i]);
	}
	ll sum = 0, ans = -INF;
	for(ll i = 1; i <= n; i++) {
		ans = max(ans, s[n] * i - sum);
		if(sz(q)) {
			sum += q.top();
			q.pop();
		}
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