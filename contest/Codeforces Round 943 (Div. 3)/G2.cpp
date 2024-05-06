#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

struct kmp {
	int n, m;
	string p, s;
	vector<int> ne;
	kmp() {}
	kmp(string pp, string ss) : p(pp), s(ss) {
		init();
	}
	void init() {
		n = sz(p);
		m = sz(s);
		p = " " + p;
		s = " " + s;
		ne.resize(n + 1);
		// 求 next 数组
		for(int i = 2, j = 0; i <= n; i++) {
			while(j && p[i] != p[j + 1]) {
				j = ne[j];
			}
			if(p[i] == p[j + 1]) {
				j += 1;
			}
			ne[i] = j;
		}
	}
	// kmp 匹配过程
	// 这道题匹配成功之后 j 不是等于 ne[j]了，而是 j 变成 0 重新匹配
	int work() {
		int cnt = 0;
		for(int i = 1, j = 0; i <= m; i++) {
			while(j && s[i] != p[j + 1]) {
				j = ne[j];
			}
			if(s[i] == p[j + 1]) {
				j += 1;
			}
			// 匹配成功
			if(j == n) {
				cnt += 1;
				j = 0;
			}
		}
		return cnt;
	}
};

void solve() {
	int n, x, y;
	string s;
	cin >> n >> x >> y >> s;
	vector<int> ans(n + 1), q(n + 1);
	vector<int> q1(n + 1), q2(n + 1), c(n + 1, -1);
	for(int i = x; i <= y; i++) {
		q[i] = i;
	}
	auto get_cnt = [&](int mid) {
		if(~c[mid]) return c[mid];

		kmp t(s.substr(0, mid), s.substr(mid));
		return c[mid] = t.work() + 1;
	};
	// [L, R]： 答案的值域
	// [l, r]: 询问的下标范围
	auto dfs = [&](auto dfs, int L, int R, int l, int r) -> void {
		if(L == R) {
			for(int i = l; i <= r; i++) {
				ans[q[i]] = R;
			}
			return;
		}
		int mid = (L + R + 1) / 2;
		int cnt = get_cnt(mid), t1 = 0, t2 = 0;
		for(int i = l; i <= r; i++) {
			if(cnt >= q[i]) {	// q[i] 的答案在 [mid, R]
				q2[++t2] = q[i];
			} else {			// q[i] 的答案在 [L, mid - 1]
				q1[++t1] = q[i];
			}
		}
		for(int i = 1; i <= t1; i++) {
			q[l + i - 1] = q1[i];
		}
		for(int i = 1; i <= t2; i++) {
			q[l + t1 + i - 1] = q2[i];
		}
		if(t1 != 0) {
			dfs(dfs, L, mid - 1, l, l + t1 - 1);
		}
		if(t2 != 0) {
			dfs(dfs, mid, R, l + t1, r);
		}
	};
	dfs(dfs, 0, n, x, y);
	for(int i = x; i <= y; i++) {
		cout << ans[i] << " \n"[i == y];
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