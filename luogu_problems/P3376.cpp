#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1210;

int n, m, s, t;
int dis[N], cur[N];
struct edge {
	int v, c, id;
	edge() {}
	edge(int _v, int _c, int _id) : v(_v), c(_c), id(_id) {}
};
vector<edge> e[N];

bool bfs() {
	fill(dis + 1, dis + 1 + n, -1);
	fill(cur + 1, cur + 1 + n, 0);
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while(sz(q)) {
		int u = q.front();
		q.pop();

		for(auto [v, c, id] : e[u]) {
			if(c > 0 && dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return ~dis[t];
}

ll dfs(int u, ll limit = INF) {
	if(u == t) return limit;

	ll flow = 0;
	for(int i = cur[u]; i < sz(e[u]) && flow < limit; i++) {
		cur[u] = i;
		auto &[v, c, id] = e[u][i];
		if(c > 0 && dis[v] == dis[u] + 1) {
			ll f = dfs(v, min(limit - flow, 1ll * c));
			flow += f;
			c -= f;
			e[v][id].c += f;
		}
	}
	return flow;
}

ll dinic() {
	ll res = 0, f;
	while(bfs()) {
		while((f = dfs(s))) {
			res += f;
		}
	}
	return res;
}

void solve() {
	cin >> n >> m >> s >> t;
	while(m--) {
		int u, v, c;
		cin >> u >> v >> c;
		int x = sz(e[u]), y = sz(e[v]);
		e[u].emplace_back(v, c, y);
		e[v].emplace_back(u, 0, x);
	}
	cout << dinic() << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}