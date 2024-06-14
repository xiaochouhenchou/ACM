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
	ll h, n;
	cin >> h >> n;
	vector<ll> a(n + 1), c(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int j = 1; j <= n; j++) {
		cin >> c[j];
	}
	auto check = [&](ll mid) -> bool {
		ll cur = h;
		for(int i = 1; i <= n && cur > 0; i++) {
			ll cnt = (mid - 1) / c[i] + 1;
			ll dam = cnt * a[i];
			cur -= dam;
		}
		return cur <= 0;
	};	
	ll l = 1, r = 1e12;
	while(l < r) {
		ll mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << r << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}