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
	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<PII>> e(n);
	vector<int> dis(n, inf), vis(n);
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].emplace_back(v, w);
	}
	auto spfa = [&] {
		dis[r] = 0;
		queue<int> q;
		q.push(r);
		vis[r] = 1;
		vector<int> cnt(n);
		while(sz(q)) {
			int u = q.front();
			q.pop();
			vis[u] = 0;

			for(auto [v, w] : e[u]) {
				if(dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					cnt[v] = cnt[u] + 1;
					if(cnt[v] >= n) {
						return true;
					}

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
	} else {
		for(int i = 0; i < n; i++) {
			if(dis[i] >= inf) {
				cout << "INF\n";
			} else {
				cout << dis[i] << '\n';
			}
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