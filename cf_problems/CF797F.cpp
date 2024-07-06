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
	int n, m;
	cin >> n >> m;
	vector<int> x(n + 1);
	vector<PII> v(m + 1);
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for(int i = 1; i <= m; i++) {
		cin >> v[i].x >> v[i].y;
	}
	sort(x.begin() + 1, x.end());
	sort(v.begin() + 1, v.end());

	/*
		f[i][j] = min(f[i - 1][k] + sum[i][j] - sum[i][k]), j - c[i] <= k <= j
		sum[i][j] = sum(abs(p[i] - x[j]))
	*/
	vector<vector<ll>> f(m + 2, vector<ll>(n + 2, INF));
	vector<ll> sum(n + 2);

	for(int i = 0; i <= m; i++) {
		f[i][0] = 0;
	}
	for(int i = 1; i <= m; i++) {
		int c = v[i].y;
		int p = v[i].x;

		ll res = 0;
		for(int j = 1; j <= n; j++) {
			res += abs(p - x[j]);
			sum[j] = res;
		}

		deque<pair<ll, ll>> q;
		q.emplace_back(f[i - 1][0] - sum[0], 0);
		
		for(int j = 1; j <= n; j++) {
			if(sz(q) && q.front().y < j - c) q.pop_front();
			while(sz(q) && q.back().x >= f[i - 1][j] - sum[j]) {
				q.pop_back();
			}
			q.emplace_back(f[i - 1][j] - sum[j], j);

			if(sz(q)) {
				f[i][j] = q.front().x + sum[j];
			}
		}
	}
	ll ans = f[m][n];
	if(ans >= INF) ans = -1;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}