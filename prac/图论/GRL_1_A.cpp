#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

typedef pair<ll, ll> PLL;
void solve() {
	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<PLL>> e(n);
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].emplace_back(v, w);
	}
	vector<ll> dis(n, INF), vis(n);
	dis[r] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> q;
	q.emplace(0, r);
	while(sz(q)) {
		auto [d, u] = q.top();
		q.pop();

		if(vis[u]) continue;
		vis[u] = 1;

		for(auto [v, w] : e[u]) {
			if(dis[v] > d + w) {
				dis[v] = d + w;
				q.emplace(dis[v], v);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(dis[i] >= INF) cout << "INF\n";
		else cout << dis[i] << '\n';
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