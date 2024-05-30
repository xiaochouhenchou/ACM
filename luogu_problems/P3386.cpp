#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1010;

int s, t, n, m, E;
int cur[N], dep[N];
struct edge {
	int v, w, id;
	edge() {}
	edge(int _v, int _w, int _id) : v(_v), w(_w), id(_id) {} 
};
vector<edge> e[N];

bool bfs() {
	fill(cur, cur + n, 0);
	fill(dep, dep + n, -1);
	queue<int> q;
	q.push(s);
	dep[s] = 0;
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
	return dep[t] != -1;
}

int dfs(int u, int limit = inf) {
	if(u == t) return limit;

	int flow = 0;
	for(int i = cur[u]; i < sz(e[u]) && flow < limit; i++) {
		cur[u] = i;
		auto &[v, w, id] = e[u][i];
		if(w > 0 && dep[v] == dep[u] + 1) {
			int f = dfs(v, min(limit - flow, w));
			w -= f;
			e[v][id].w += f;
			flow += f;
		}
	}
	return flow;
}

int dinic() {
	int res = 0, f;
	while(bfs()) {
		while((f = dfs(s))) res += f;
	}
	return res;
}

void add(int u, int v) {
	int x = sz(e[u]), y = sz(e[v]);
	e[u].emplace_back(v, 1, y);
	e[v].emplace_back(u, 0, x);
}

void solve() {
	cin >> n >> m >> E;
	while(E--) {
		int u, v;
		cin >> u >> v;
		v += n;
		add(u, v);
	}
	for(int i = 1; i <= n; i++) {
		add(0, i);
	}
	for(int i = n + 1; i <= n + m; i++) {
		add(i, n + m + 1);
	}
	n += m + 2;
	s = 0, t = n - 1;
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