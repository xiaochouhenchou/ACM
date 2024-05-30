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

int m, n, s, t;
int dep[N], cur[N];
struct edge {
	int v, c, id;
	edge() {}
	edge(int _v, int _c, int _id) : v(_v), c(_c), id(_id) {}
};
vector<edge> e[N];

bool bfs() {
	fill(dep, dep + n, -1);
	fill(cur, cur + n, 0);
	queue<int> q;
	q.push(s);
	dep[s] = 0;
	while(sz(q)) {
		int u = q.front();
		q.pop();

		for(auto [v, c, id] : e[u]) {
			if(c > 0 && dep[v] == -1) {
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
		auto &[v, c, id] = e[u][i];
		if(c > 0 && dep[v] == dep[u] + 1) {
			int f = dfs(v, min(limit - flow, c));
			c -= f;
			e[v][id].c += f;
			flow += f;
		}
	}
	return flow;
}

void add(int u, int v) {
	int x = sz(e[u]), y = sz(e[v]);
	e[u].emplace_back(v, 1, y);
	e[v].emplace_back(u, 0, x);
}

void solve() {	
	cin >> m >> n;
	int u, v;
	while(cin >> u >> v, ~u) {
		add(u, v);
	}
	for(int i = 1; i <= m; i++) {
		add(0, i);
	}
	for(int i = m + 1; i <= n; i++) {
		add(i, n + 1);
	}
	n += 2;
	s = 0, t = n - 1;
	int res = 0, f;
	while(bfs()) {
		while((f = dfs(s))) res += f;
	}
	cout << res << '\n';
	for(int u = 1; u <= m; u++) {
		for(auto [v, c, id] : e[u]) {
			if(!c && m + 1 <= v && v <= n) {
				cout << u << ' ' << v << '\n';
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