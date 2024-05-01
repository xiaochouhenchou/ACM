#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(auto &x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	auto check = [&](ll mid) {
		ll cur = k;
		for(auto &x : a) {
			ll tmp = max(mid - x, 0ll);
			if(cur < tmp) return false;
			cur -= tmp;
		}
		return true;
	};
	ll l = 1, r = INF;
	while(l < r) {
		ll mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	// cout << ": " << r << '\n';
	for(auto &x : a) {
		k -= max(r - x, 0ll);
	}
	
	ll ans = r * n;
	while(sz(a)) {
		if(a.back() > r) {
			ans += 1;
			a.pop_back();
		} else if(k) {
			ans += 1;
			k -= 1;
			a.pop_back();
		} else {
			break;
		}
	}
	ans = ans - n + 1;
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
