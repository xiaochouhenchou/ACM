#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// 找最小环

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> e(n + 1);
	vector<int> dg(n + 1), vis(n + 1);
	for(int i = 1, t; i <= n; i++) {
		cin >> t;
		e[i].push_back(t);
		dg[t] += 1;
	}
	{
		queue<int> q;
		for(int i = 1; i <= n; i++) {
			if(!dg[i]) q.emplace(i);
		}
		while(sz(q)) {
			int u = q.front();
			vis[u] = 1;
			q.pop();

			for(int v : e[u]) {
				if(--dg[v] == 0) q.emplace(v);
			}
		}
	}
	int ans = n;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			int u = i, cnt = 0;
			while(!vis[u]) {
				cnt += 1;
				vis[u] = 1;
				for(int v : e[u]) {
					if(!vis[v]) {
						u = v;
						break;
					}
				}
			}
			ans = min(ans, cnt);
		}
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