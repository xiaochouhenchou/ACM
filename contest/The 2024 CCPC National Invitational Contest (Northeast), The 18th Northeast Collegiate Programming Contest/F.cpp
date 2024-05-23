#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

ll p, x, k, ans;
vector<ll> a, b;

void dfs(int u, ll cur) {
	if(u == sz(b)) {
		for(ll e : a) {
			if(cur <= x / e) ans += 1;
			else break;
		}
		return;
	}

	while(true) {
		dfs(u + 1, cur);
		if(cur > x / b[u]) break;
		cur *= b[u];
	}
}

void solve() {
	cin >> p >> x >> k;
	for(ll i = 2; i <= k / i; i++) {
		if(k % i == 0) {
			while(k % i == 0) k /= i;
			b.push_back(i);
		}
	}
	if(k > 1) {
		b.push_back(k);
	}
	for(auto e : b) {
		while(p % e == 0) p /= e;
	}

	for(ll i = 1; i <= p / i; i++) {
		if(p % i == 0) {
			a.push_back(i);
			if(i != p / i) a.push_back(p / i);
		}
	}
	sort(a.begin(), a.end());
	dfs(0, 1);
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