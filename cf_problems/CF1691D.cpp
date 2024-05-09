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
	vector<int> a(n + 2), l(n + 2), r(n + 2), lg(n + 1);
	vector<ll> s(n + 1);
	vector<vector<ll>> f(n + 1, vector<ll>(19));
	vector<vector<ll>> g(n + 1, vector<ll>(19));
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 2; i <= n; i++) {
		lg[i] = lg[i >> 1] + 1;
	}
	for(int j = 0; j <= 18; j++) {
		for(int i = 0; i + (1 << j) - 1 <= n; i++) {
			if(!j) {
				f[i][j] = g[i][j] = s[i];
			} else {
				g[i][j] = max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
				f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	{
		vector<int> stk;
		a[0] = inf;
		stk.push_back(0);
		for(int i = 1; i <= n; i++) {
			while(sz(stk) && a[stk.back()] <= a[i]) {
				stk.pop_back();
			}
			l[i] = stk.back();
			stk.push_back(i);
		}
	}
	{
		vector<int> stk;
		a[n + 1] = inf;
		stk.push_back(n + 1);
		for(int i = n; i; i--) {
			while(sz(stk) && a[stk.back()] <= a[i]) {
				stk.pop_back();
			}
			r[i] = stk.back();
			stk.push_back(i);
		}
	}

	auto get_max = [&](int l, int r) {
		int k = lg[r - l + 1];
		return max(g[l][k], g[r - (1 << k) + 1][k]);
	};
	auto get_min = [&](int l, int r) {
		int k = lg[r - l + 1];
		return min(f[l][k], f[r - (1 << k) + 1][k]);
	};
	for(int i = 1; i <= n; i++) {
		ll y = get_max(i, r[i] - 1);
		ll x = get_min(l[i], i - 1);
		if(a[i] < y - x) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}