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
	ll x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> divisors;
	for(ll i = 1; i <= k / i; i++) {
		if(k % i == 0) {
			divisors.push_back(i);
			if(k / i != i) divisors.push_back(k / i);
		}
	}	
	ll ans = 0;
	for(ll a : divisors) {
		if(a > x) continue;
		for(ll b : divisors) {
			if(b > y) continue;
			if(k / b % a) continue;
			if(k / a / b > z) continue;
			// cout << a << ' ' << b << ' ' << k / a / b << '\n';
			ans = max(ans, (x - a + 1) * (y - b + 1) * 
				(z - k / a / b + 1));
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