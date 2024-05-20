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
	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = inf;
	auto dfs = [&](auto dfs, int t, int dep) {
		if(dep > ans) return;
		if(dep > n * 3) return;
		auto b = a;
		sort(b.begin() + 1, b.end());
		if(a == b) {
			ans = dep;
			return;
		}

		for(int i = 1; i <= n; i++) {
			if(a[i] <= t) continue;
			swap(a[i], t);
			dfs(dfs, t, dep + 1);
			swap(a[i], t);
		}
	};
	dfs(dfs, x, 0);
	if(ans == inf) ans = -1;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}