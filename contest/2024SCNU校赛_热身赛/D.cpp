#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

struct bitTree {
	int n;
	vector<int> tr;
	bitTree() {}
	bitTree(int sz) : n(sz) {
		tr.resize(n + 1, 0);
	}
	int lowbit(int x) { return x & -x; }
	void add(int x, int v) {
		while(x <= n) {
			tr[x] += v;
			x += lowbit(x);
		}
	}
	int sum(int x) {
		int res = 0;
		while(x) {
			res += tr[x];
			x -= lowbit(x);
		}
		return res;
	}
};

const int N = 100010;

ll n, k, m;
ll a[N], s[N], v[N];

/*
	思路: 二分区间和第 k 大的值。 check(mid) 函数中计算 s[r] - s[l] >= mid 
		 的数量 cnt，枚举左端点 l 二分右端点 r 的个数。 因为 s[i] 有可能 < 0，
		 因此不能直接二分 r，需要用树状数组离散化所有用到的值。 cnt >= k 说明
		 答案 >= mid，否则答案 < mid
*/
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	auto check = [&](ll x) {
		m = 0;
		for(int i = 0; i <= n; i++) {
			v[++m] = s[i];
			v[++m] = s[i] + x; 
		}
		sort(v + 1, v + 1 + m);
		m = unique(v + 1, v + 1 + m) - v - 1;
		auto get_val = [&](ll x) {
			return lower_bound(v + 1, v + 1 + m, x) - v;
		};

		bitTree tr(m);
		ll cnt = 0;
		for(int i = n; i >= 0; i--) {
			cnt += tr.sum(m) - tr.sum(get_val(s[i] + x) - 1);
			tr.add(get_val(s[i]), 1);
		}
		return cnt >= k;
	};

	ll l = -inf, r = inf;
	while(l < r) {
		ll mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << r << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}