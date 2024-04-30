#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const double eps = 1e-8;
const int mod = 1e9 + 9;

struct bitTree {
	int n;
	vector<int> tr;
	bitTree() {}
	bitTree(int sz) : n(sz) {
		tr.resize(sz + 1, 0);
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

void solve() {
	int n, k;
	cin >> n >> k;
	vector<string> s(n + 1);
	vector<int> pre(n + 1);
	vector<LL> v;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		pre[i] = pre[i - 1] + (s[i] == "byl");
	}
	for(int i = 0; i <= n; i++) {
		v.push_back(1ll * (k + 1) * pre[i] - 1ll * i * k);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	LL ans = 0;
	bitTree tr(n + 1);
	for(int r = 0; r <= n; r++) {
		LL val = 1ll * (k + 1) * pre[r] - 1ll * r * k;
		val = lower_bound(v.begin(), v.end(), val) - v.begin() + 1;
		ans += tr.sum(val - 1);
		tr.add(val, 1);
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
