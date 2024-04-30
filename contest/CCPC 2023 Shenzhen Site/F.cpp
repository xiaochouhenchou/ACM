#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> dg(n + 1);
	vector<vector<int>> e(n + 1);
	for(int i = 1, u, v; i <= n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		dg[v] += 1, dg[u] += 1;
	}
	map<int, int> mp;
	for(int i = 1; i <= n; i++) {
		mp[dg[i]] += 1;
	}

	vector<int> vis(n + 1);
	{
		auto d = dg;
		queue<int> q;
		for(int i = 1; i<= n; i++) {
			if(d[i] == 1) {
				q.push(i);
			}
		}
		while(sz(q)) {
			int u = q.front();
			q.pop();

			vis[u] = 1;
			for(int v : e[u]) {
				if(--d[v] == 1) {
					q.push(v);
				}
			}
		}
	}
	vector<int> circle;
	auto dfs = [&](auto dfs, int u) -> void {
		vis[u] = 1;
		circle.push_back(u);
		for(int v : e[u]) {
			if(!vis[v]) {
				dfs(dfs, v);
			}
		}
	};
	for(int i = 1; i <= n; i++) {
		// cout << dg[i] << " \n"[i == n];
		if(!vis[i]) {
			dfs(dfs, i);
		}
	}

	LL ans = 0;
	for(int i = 0; i < sz(circle); i++) {
		int u = circle[i], v = circle[(i + 1) % sz(circle)];
		if(--mp[dg[u]] == 0) {
			mp.erase(mp.find(dg[u]));
		}
		if(--mp[dg[v]] == 0) {
			mp.erase(mp.find(dg[v]));
		}
		mp[dg[u] - 1] += 1;
		mp[dg[v] - 1] += 1;

		if(mp.rbegin()->x <= 4) {
			int res = 0;
			for(int i = 1; i <= 3; i++) {
				if(mp.count(i)) res += mp[i];
			}
			ans += res;
		}

		if(--mp[dg[u] - 1] == 0) {
			mp.erase(mp.find(dg[u] - 1));
		}
		if(--mp[dg[v] - 1] == 0) {
			mp.erase(mp.find(dg[v] - 1));
		}
		mp[dg[u]] += 1;
		mp[dg[v]] += 1;
		
	}
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