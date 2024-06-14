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
	枚举 i，二分找最大的 x 使得 [1, x] 的人本应去的岗位都能满足（排除 i 的贡献）。 
	那么 > x 对答案的贡献都是 sum[a[j]] 或 sum[b[j]]
*/
void solve() {
	int n, m;
	cin >> n >> m;
	int len = n + m + 1;
	vector<int> a(len + 2), b(len + 2), p(len + 2), t(len + 2);
	vector<ll> suf_a(len + 2), suf_b(len + 2), res(len + 2);
	for(int i = 1; i <= len; i++) {
		cin >> a[i];
	} 
	for(int i = 1; i <= len; i++) {
		cin >> b[i];
	}
	for(int i = 1; i <= len; i++) {
		p[i] = p[i - 1] + (a[i] > b[i]);
		t[i] = t[i - 1] + (a[i] < b[i]);
		res[i] = res[i - 1] + (a[i] > b[i] ? a[i] : b[i]);
	}
	for(int i = len; i; i--) {
		suf_a[i] = suf_a[i + 1] + a[i];
		suf_b[i] = suf_b[i + 1] + b[i];
	}
	auto calc = [&](int i) {
		int l = 0, r = len;
		while(l < r) {
			int mid = (l + r + 1) / 2;
			int c1 = p[mid] - (i <= mid ? (a[i] > b[i]) : 0);
			int c2 = t[mid] - (i <= mid ? (a[i] < b[i]) : 0);
			if(c1 <= n && c2 <= m) l = mid;
			else r = mid - 1;
		}
		// cout << i << ' ' << r << '\n';
		int c1 = p[r + 1] - (i <= r + 1 ? (a[i] > b[i]) : 0);
		ll ans = res[r] + (c1 > n ? suf_b[r + 1] : suf_a[r + 1]);
		if(i <= r) {
			ans -= (a[i] > b[i] ? a[i] : b[i]);
		} else {
			ans -= (c1 > n ? b[i] : a[i]);
		}
		return ans;
	};
	for(int i = 1; i <= len; i++) {
		cout << calc(i) << " \n"[i == len];
		// cout << calc(i) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}