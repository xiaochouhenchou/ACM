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
	int n, m;
	cin >> n >> m;
	vector<vector<PLL>> e(n);
	vector<vector<ll>> dis(n, vector<ll>(n, INF));
	for(int i = 0; i < n; i++) dis[i][i] = 0;
	while(m--) {
		ll u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = min(dis[u][v], w);
		e[u].emplace_back(v, w);
	}
	auto spfa = [&] {
		vector<ll> vis(n), d(n), cnt(n);
		queue<int> q;
		for(int i = 0; i < n; i++) {
			q.push(i);
			vis[i] = 1;
		}
		while(sz(q)) {
			int u = q.front();
			q.pop();
			vis[u] = 0;

			for(auto [v, w] : e[u]) {
				if(d[v] > d[u] + w) {
					d[v] = d[u] + w;
					cnt[v] = cnt[u] + 1;
					if(cnt[v] >= n) return true;
					if(!vis[v]) {
						q.push(v);
						vis[v] = 1;
					}
				}
			}
		}	
		return false;
	};
	if(spfa()) {
		cout << "NEGATIVE CYCLE\n";
		return;
	}

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(dis[i][j] >= INF / 2) cout << "INF";
			else cout << dis[i][j];
			cout << " \n"[j == n - 1];
		}
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