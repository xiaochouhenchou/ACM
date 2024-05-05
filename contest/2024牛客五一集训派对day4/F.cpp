#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 20;

int a[N];
ll f[N][N][N][N][163];

ll dfs(int pos, int lead, int limit, int s0, int s1, int s2, int s, int flag) {
	if(!pos) {
		return !lead && flag;
	}
	auto &v = f[pos][s0][s1][s2][s];
	if(!lead && !limit && ~v) return v;
	ll res = 0;
	int up = (limit ? a[pos] : 9);
	for(int i = 0; i <= up; i++) {
		int next_lead = lead && !i;
		int next_limit = limit && i == up;
		int next_s = s + i, r = next_s % 3;
		int next_s0 = next_lead ? s0 : s0 + (r == 0);
		int next_s1 = s1 + (r == 1);
		int next_s2 = s2 + (r == 2);
		int next_flag = flag || (!next_lead && r == 0 && s0) || 
						(r == 1 && s1) || (r == 2 && s2);

		res += dfs(pos - 1, next_lead, next_limit, 
			next_s0, next_s1, next_s2, next_s, next_flag);
	}
	return (lead ? res : (limit ? res : v = res));
}

ll calc(ll x) {
	int cnt = 0;
	while(x) {
		a[++cnt] = x % 10;
		x /= 10;
	}
	return dfs(cnt, 1, 1, 1, 0, 0, 0, 0);
}

void solve() {
	ll l, r;
	cin >> l >> r;
	// cout << calc(r) << '\n';
	// cout << calc(l - 1) << '\n';
	cout << (calc(r) - calc(l - 1)) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(f, -1, sizeof f);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;	
}
