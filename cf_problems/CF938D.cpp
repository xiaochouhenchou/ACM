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
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> e(n + 1);
	vector<ll> dis(n + 1);
	while(m--) {
		ll u, v, w;
		cin >> u >> v >> w;
		w *= 2;
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	} 
	for(int i = 1; i <= n; i++) {
		cin >> dis[i];
	}

	{
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, 
						greater<pair<ll, ll>>> q;
		for(int i = 1; i <= n; i++) {
			q.emplace(dis[i], i);
		}
		vector<bool> vis(n + 1);
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
	}
	for(int i = 1; i <= n; i++) {
		cout << dis[i] << " \n"[i == n];
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