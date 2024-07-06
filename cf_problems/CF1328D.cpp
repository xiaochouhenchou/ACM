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
	vector<int> t(n);
	vector<vector<int>> e(n);
	for(int i = 0; i < n; i++) {
		cin >> t[i];
	}
	int m = 0;
	for(int i = 0; i < n; i++) {
		if(t[i] != t[(i + 1) % n]) {
			e[i].push_back((i + 1) % n);
			e[(i + 1) % n].push_back(i);
			m += 1;
		}
	}
	if(m >= n) {
		if(n % 2 == 0) {
			cout << 2 << '\n';
			for(int i = 1; i <= n; i++) {
				cout << i % 2 + 1 << " \n"[i == n];
			}
		} else {
			cout << 3 << '\n';
			for(int i = 1; i <= n - 1; i++) {
				cout << i % 2 + 1 << ' ';
			}
			cout << 3 << '\n';
		}
		return;
	}

	vector<int> ans(n);
	auto dfs = [&](auto dfs, int u, int val) -> void {
		ans[u] = val;
		for(int v : e[u]) {
			if(ans[v]) continue;
			dfs(dfs, v, 3 - val);
		}
	};
	
	int k = 0;
	for(int i = 0; i < n; i++) {
		if(!ans[i]) dfs(dfs, i, 1);
		k = max(k, ans[i]);
	}
	cout << k << '\n';
	for(int i = 0; i < n; i++) {
		cout << ans[i] << " \n"[i == n - 1];
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