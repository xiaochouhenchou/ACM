#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

/*
	注意到 a^b 当 b >= 3 的时候，符合条件的 a 只有 1e6 个。 直接枚举 a、b 放进数组里（注意
	去重，比如 2^10 会和 4^5 重复）
	与此同时，a^b 当 b = 2 的时候，符合条件的数只有 t = 根号 n 个。 那么答案即为（上面数组的
	大小）+ t？当然不是。这些完全平方数也会和数组里的数重复，如 2^6 会和 8^2 重复。我们枚举数组
	里的数，如果它是完全平方数，那么答案减 1。（因为这个数在 b >= 3 的时候已经被算过了）
*/

void solve() {
	ll n;
	cin >> n;
	vector<ll> nums;
	for(ll a = 2; a * a * a <= n; a++) {
		ll x = a * a * a;
		while(true) {
			nums.push_back(x);
			if(x > n / a) break;
			x *= a;
		}
	}
	// 去重
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	ll t = sqrtl(n);
	ll ans = sz(nums) + t;

	for(auto x : nums) {
		ll sq = sqrtl(x);
		if(sq * sq == x) ans -= 1;
	}

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