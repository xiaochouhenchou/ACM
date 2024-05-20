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
	思路： 
			a[i + 1] - a[i] = 1 
		<->	[a[i + 1] - (i + 1)] - (a[i] - i) = 0
		<-> a[i + 1] - (i + 1) = a[i] - i	
		因此先把每个 a[i] <- a[i] - i，问题转化成操作最多 k 次使得
		某个连续区间的数都相同。
		每个区间 [l, r] 变成相同的数 x 的花费是 |x -	a[l]| + 
		|x - a[l + 1]| + ... + |x - a[r]|，由绝对值不等式可知
		x 取 a[l, r] 的中位数这个花费是最小的。 如果区间 [l, r] 的
		花费是 x, x <= k，那么 [l, r - 1] 的花费也<= k，因此双
		指针扫一遍序列用两个 set 维护中位数即可知道区间是否合法，
		答案取合法区间的最大长度即可。
		用 set 而不是用堆的原因是涉及删除特定元素。用两个堆维护中位数
		的技巧可见洛谷 P1168。
*/
void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= i;
	}
	multiset<ll> up, down;
	ll sum_up = 0, sum_down = 0;
	auto insert = [&](ll x, ll &sum, multiset<ll> &st) {
		sum += x;
		st.insert(x);
	};
	auto erase = [&](ll x, ll &sum, multiset<ll> &st) {
		sum -= x;
		st.erase(st.find(x));
	};
	auto work = [&] {
		while(sz(down) > sz(up) + 1) {
			auto it = down.rbegin();
			insert(*it, sum_up, up);
			erase(*it, sum_down, down);
		}
		while(sz(up) > sz(down)) {
			auto it = up.begin();
			insert(*it, sum_down, down);
			erase(*it, sum_up, up);
		}
	};
	auto merge = [&](ll x) {
		if(!sz(down) || x <= *down.rbegin()) {
			insert(x, sum_down, down);
		} else {
			insert(x, sum_up, up);
		}
		work();
	};
	auto remove = [&](ll x) {
		if(down.find(x) != down.end()) {
			erase(x, sum_down, down);
		} else {
			erase(x, sum_up, up);
		}
		work();
	};
	auto cost = [&](ll x) {
		return x * sz(down) - sum_down + sum_up - x * sz(up);
	};
	auto check = [&](ll x) {
		merge(x);
		ll mid = *down.rbegin();
		if(cost(mid) <= k) return true;
		remove(x);
		return false;
	};
	int ans = 0;
	for(int i = 1, j = 1; i <= n; i++) {
		while(j <= n && check(a[j])) {
			j += 1;
		}
		ans = max(ans, j - i);
		remove(a[i]);
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