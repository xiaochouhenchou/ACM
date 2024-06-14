#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// 找出环上的点并标记，环上的点的答案为环的大小，不在环上的点答案就 dfs 递推
void solve() {
	int n;
	cin >> n;
	vector<vector<int>> e(n + 1);
	vector<int> dg(n + 1), vis(n + 1), ans(n + 1);
	for(int i = 1, t; i <= n; i++) {
		cin >> t;
		e[i].push_back(t);
		dg[t] += 1;
	}
	{
		queue<int> q;
		for(int i = 1; i <= n; i++) {
			if(!dg[i]) q.push(i);
		}
		while(sz(q)) {
			int u = q.front();
			vis[u] = 1;
			q.pop();

			for(int v : e[u]) {
				if(--dg[v] == 0) q.push(v);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			int u = i;
			vector<int> tmp;
			while(!vis[u]) {
				vis[u] = 1;
				tmp.push_back(u);
				for(int v : e[u]) {
					if(!vis[v]) {
						u = v;
						break;
					}
				}
			}
			for(int x : tmp) {
				ans[x] = sz(tmp);
			}
		}
	}
	auto dfs = [&](auto dfs, int u) -> int {
		if(ans[u]) return ans[u];
		for(int v : e[u]) {
			return ans[u] = dfs(dfs, v) + 1;
		}
		return -1;
	};
	for(int i = 1; i <= n; i++) {
		if(!ans[i]) dfs(dfs, i);
	}
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}