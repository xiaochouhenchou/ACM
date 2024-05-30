#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 5010;

int n, m, s, t;
int dis[N], cur[N], cnt[N], vis[N];
struct edge {
	int v, c, w, id;	// 终点、容量、单位花费、反向边编号
	edge() {}
	edge(int _v, int _c, int _w, int _id) : v(_v), c(_c), w(_w), id(_id) {}
};
vector<edge> e[N];

bool spfa() {
	for(int i = 1; i <= n; i++) {
		cur[i] = cnt[i] = vis[i] = 0;
		dis[i] = inf;
	}
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	while(sz(q)) {
		int u = q.front();
		q.pop();
		vis[u] = 0;

		for(auto [v, c, w, id] : e[u]) {
			if(c > 0 && dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u] + 1;

				if(cnt[v] >= n) return false;	// 有负环
				if(!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	return dis[t] != inf;	// 从源点出发能走到汇点
}

int dfs(int u, int limit = inf) {
	if(u == t) {
		return limit;
	}

	vis[u] = 1;
	int flow = 0;
	for(int i = cur[u]; i < sz(e[u]) && flow < limit; i++) {
		cur[u] = i;		// 当前弧优化
		auto &[v, c, w, id] = e[u][i];
		if(c > 0 && !vis[v] && dis[v] == dis[u] + w) {
			int f = dfs(v, min(limit - flow, c));
			c -= f;
			flow += f;
			e[v][id].c += f;
		}
	}
	vis[u] = 0;
	return flow;
}

void solve() {
	cin >> n >> m >> s >> t;
	while(m--) {
		int u, v, c, w;
		cin >> u >> v >> c >> w;
		int x = sz(e[u]), y = sz(e[v]);
		e[u].emplace_back(v, c, w, y);
		e[v].emplace_back(u, 0, -w, x);
	}
	int maxFlow = 0, minCost = 0;
	while(spfa()) {
		int flow;
		while((flow = dfs(s))) {
			maxFlow += flow;
			minCost += flow * dis[t];
		}
	}
	cout << maxFlow << ' ' << minCost << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}