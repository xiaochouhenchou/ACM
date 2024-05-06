#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
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
	int n, l, r;
	cin >> n >> l >> r;
	string s;
	cin >> s;
	int low = 0, high = n;
	auto check = [&](int mid) {
		kmp t(s.substr(0, mid), s.substr(mid));
		return t.work() >= r - 1;
	};
	while(low < high) {
		int mid = (low + high + 1) / 2;
		if(check(mid)) low = mid;
		else high = mid - 1;
	}
	cout << high << '\n';	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	// freopen("out.txt", "r", stdin);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;	
}
