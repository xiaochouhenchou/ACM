#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 998244353;

void add(ll &c, ll a, ll b) {
	c = (a + b) % mod;
	c = (c + mod) % mod;
}

void solve() {
	int n, m;
	cin >> n >> m;
	string c;
	cin >> c;
	c = " " + c;
	vector<ll> cnt_b(n + 1), cnt_w(n + 1);		// 黑白数量的和
	vector<ll> sum_b(n + 1), sum_w(n + 1);		// 黑白下标的和
	vector<ll> ans(n + 1);						// [1, i] 的答案
	for(int i = 1; i <= n; i++) {
		add(cnt_b[i], cnt_b[i - 1], c[i] == '1');
		add(cnt_w[i], cnt_w[i - 1], c[i] == '0');
		add(sum_b[i], sum_b[i - 1], (c[i] == '1' ? i : 0));
		add(sum_w[i], sum_w[i - 1], (c[i] == '0' ? i : 0));
	}
	for(int i = 1; i <= n; i++) {
		if(c[i] == '1') {
			ll res = cnt_w[i - 1] * i % mod;
			add(res, res, -sum_w[i - 1]);
			add(ans[i], ans[i - 1], res);
		} else {
			ll res = cnt_b[i - 1] * i % mod;
			add(res, res, -sum_b[i - 1]);
			add(ans[i], ans[i - 1], res);
		}
	}
	while(m--) {
		int l, r;
		cin >> l >> r;
		ll res = 0;
		add(res, ans[r], -ans[l - 1]);
		add(res, res, -cnt_b[l - 1] * (sum_w[r] - sum_w[l - 1]) % mod);
		add(res, res, sum_b[l - 1] * (cnt_w[r] - cnt_w[l - 1]) % mod);
		add(res, res, -cnt_w[l - 1] * (sum_b[r] - sum_b[l - 1]) % mod);
		add(res, res, sum_w[l - 1] * (cnt_b[r] - cnt_b[l - 1]) % mod);
		cout << res << '\n'; 
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}