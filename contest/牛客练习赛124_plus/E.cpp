#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const int mod = 1e9 + 7;

void solve() {	
	int n;
	string s;
	cin >> n >> s;
	s = " " + s;
	vector<LL> v(n + 2), c(n + 2);
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	auto get_score = [&](int i, int j) {
		LL res = v[i] * v[j];
		if(s[i] != '(') res -= c[i];
		if(s[j] != ')') res -= c[j];
		return res;
	};
	// f[l][r]： 让 [l, r] 全部匹配的最大得分（就是区间 [l, r] 没有多余的括号）
	// pre[i]： 前 i 个括号的最大得分
	// suf[i]: 后 i 个括号的最大得分
	vector<vector<LL>> f(n + 2, vector<LL>(n + 2, -INF));
	vector<LL> pre(n + 2), suf(n + 2);
	for(int l = n - 1; l; l--) {
		for(int r = l + 1; r <= n; r += 2) {
			if(l + 1 == r) {
				f[l][r] = max(f[l][r], get_score(l, r));
			} else {
				f[l][r] = max(f[l][r], f[l + 1][r - 1] + get_score(l, r));
			}

			for(int k = l; k < r; k++) {
				f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] - (s[i] != ')' ? c[i] : 0);
		for(int j = 1; j <= i; j++) {
			pre[i] = max(pre[i], pre[j - 1] + f[j][i]);
		}
	}
	for(int i = n; i; i--) {
		suf[i] = suf[i + 1] - (s[i] != '(' ? c[i] : 0);
		for(int j = i; j <= n; j++) {
			suf[i] = max(suf[i], suf[j + 1] + f[i][j]);
		}
	}

	LL ans = -INF;
	for(int i = 1; i <= n + 1; i++) {
		ans = max(ans, pre[i - 1] + suf[i]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;	
	while(t--) {
		solve();
	}
	return 0;
}
