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
	int n;
	cin >> n;
	vector<int> a(n + 1), ans(n + 1), c;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(~a[i]) {
			c.push_back(i);
			ans[i] = a[i];
		}
	}
	if(!sz(c)) {
		for(int i = 1; i <= n; i++) {
			cout << i % 2 + 1 << " \n"[i == n];
		}
		return;
	}
	
	auto work = [&](int l, int r) {
		int cnt = r - l;
		string s = "", t = "";
		for(int i = 30, ok = 0; i >= 0; i--) {
			int v = a[l] >> i & 1;
			if(v) ok = 1;
			if(ok) s.push_back(v + '0');
		}
		for(int i = 30, ok = 0; i >= 0; i--) {
			int v = a[r] >> i & 1;
			if(v) ok = 1;
			if(ok) t.push_back(v + '0');
		}

		int idx = 0;
		while(idx < min(sz(s), sz(t))) {
			if(s[idx] != t[idx]) break;
			idx += 1;
		}

		int cnt1 = (sz(s) - idx);
		int cnt2 = (sz(t) - idx);
		int need = cnt1 + cnt2;
		// cout << cnt1 << ' ' << cnt2 << ' ' << idx << '\n';
		// cout << s << ' ' << t << '\n';
		if(cnt < need || (cnt - need) % 2) return false;

		ans[l] = a[l];
		l += 1;
		while(cnt1--) {
			ans[l] = ans[l - 1] / 2;
			l += 1;
		}
		while(idx < sz(t)) {
			if(t[idx] == '0') {
				ans[l] = ans[l - 1] * 2;
			} else {
				ans[l] = ans[l - 1] * 2 + 1;
			}
			idx += 1, l += 1;
		}

		int op = 1;
		while(l <= r) {
			if(op) {
				ans[l] = ans[l - 1] * 2;
			} else {
				ans[l] = ans[l - 1] / 2;
			}
			op ^= 1, l += 1;
		}
		return true;
	};
	for(int i = 0; i + 1 < sz(c); i++) {
		if(!work(c[i], c[i + 1])) {
			// cout << c[i] << ' ' <<  c[i + 1] << '\n';
			cout << -1 << '\n';
			return;
		}
	}
	for(int i = c[0] - 1; i; i--) {
		if((c[0] - i) & 1) {
			ans[i] = ans[i + 1] * 2;
		} else {
			ans[i] = ans[i + 1] / 2;
		}
	}
	for(int i = c.back() + 1; i <= n; i++) {
		if((i - c.back()) & 1) {
			ans[i] = ans[i - 1] * 2;
		} else {
			ans[i] = ans[i - 1] / 2;
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " \n"[i == n];
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