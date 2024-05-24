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
	vector<vector<int>> e(n);
	vector<int> dg(n);
	while(m--) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		dg[v] += 1;
	}
	vector<int> ans;
	{
		queue<int> q;
		for(int i = 0; i < n; i++) {
			if(!dg[i]) q.push(i);
		}
		while(sz(q)) {
			int u = q.front();
			q.pop();
			ans.push_back(u);

			for(int v : e[u]) {
				if(--dg[v] == 0) {
					q.push(v);
				}
			}
		}
	}
	for(int x : ans) {
		cout << x << '\n';
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