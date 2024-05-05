#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	ll l, r;
	cin >> l >> r;
	ll ans = 0;
	auto check = [&](ll x) {
		string s = to_string(x);
		int cnt[3] = {1, 0, 0}, sum = 0;
		for(char c : s) {
			sum = (sum + c - '0') % 3;
			if(cnt[sum]) return 1;
			cnt[sum] += 1;
		}
		return 0;
	};
	for(ll x = l; x <= r; x++) {
		ans += check(x);
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
