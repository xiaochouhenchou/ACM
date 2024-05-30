#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 110;

// O(V^2E)
int n, m, s, t, dep[N];
struct edge {
	int v, w, id;	// id 是对应反向边的编号
	edge() {}
	edge(int _v, int _w, int _id) : v(_v), w(_w), id(_id) {}
};
vector<edge> e[N];
int cur[N];		// 当前弧优化数组	

bool bfs() {
	for(int i = 0; i < n; i++) {
		dep[i] = -1;
		cur[i] = 0;
	}
	queue<int> q;
	dep[s] = 0;
	q.push(s);
	while(sz(q)) {
		int u = q.front();
		q.pop();

		for(auto [v, w, id] : e[u]) {
			if(w > 0 && dep[v] == -1) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return dep[t] != -1;		// 源点出发能到达汇点
}

int dfs(int u, int limit = inf) {
	if(u == t) return limit;

	int flow = 0;
	for(int i = cur[u]; i < sz(e[u]) && flow < limit; i++) {
		cur[u] = i;		// 当前弧优化
		auto &[v, w, id] = e[u][i];
		if(w > 0 && dep[v] == dep[u] + 1) {
			int f = dfs(v, min(limit - flow, w));
			w -= f;
			flow += f;
			e[v][id].w += f;
		}
	}
	return flow;
}

void solve() {
	cin >> n >> m;
	s = 0, t = n - 1;
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		int x = sz(e[u]), y = sz(e[v]);
		e[u].emplace_back(v, w, y);		// u -> v 反向边为 v -> u
		e[v].emplace_back(u, 0, x);		// v -> u 反向边为 u -> v
	}
	int ans = 0;
	while(bfs()) {
		int flow;
		while((flow = dfs(s))) ans += flow;
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