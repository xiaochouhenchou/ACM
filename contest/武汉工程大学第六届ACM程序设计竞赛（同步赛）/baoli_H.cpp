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

void solve() {
	int n, k, s;
	cin >> n >> k >> s;
	vector<int> a(n);
	auto check = [&] {
		for(int i = 0; i < k; i++) {
			for(int j = i + k; j < n; j += k) {
				a[j] = a[i];
			}
		}
		int ok = 1;
		for(int i = 0; i + 1 < n; i++) {
			if(a[i] == a[i + 1]) {
				ok = 0;
				break;
			}
		}
		if(accumulate(a.begin(), a.end(), 0ll) > s) {
			ok = 0;
		}
		return ok;
	};
	auto dfs = [&](auto dfs, int u, int sum) -> void {
		if(sum > s) return;
		if(u == min(n, k)) {
			if(check()) {
				cout << "YES\n";
				for(int i = 0; i < n; i++) {
					cout << a[i] << " \n"[i == n - 1];
				}
				exit(0);
			}
			return;
		}
		for(int i = 1; i <= k; i++) {
			if(u && i == a[u - 1]) continue;
			a[u] = i;
			dfs(dfs, u + 1, sum + a[u]);
		}
	};
	dfs(dfs, 0, 0);
	cout << "NO\n";
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
