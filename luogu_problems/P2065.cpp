#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 10010;

int m, n, s, t, len, b[N], r[N];
int dis[N], cur[N];
struct edge {
	int v, c, id;
	edge() {}
	edge(int _v, int _c, int _id) : v(_v), c(_c), id(_id) {}
};
vector<edge> e[N];

void add(int u, int v, int c) {
	int x = sz(e[u]), y = sz(e[v]);
	e[u].emplace_back(v, c, y);
	e[v].emplace_back(u, 0, x);
}

bool bfs() {
	fill(dis, dis + 1 + len, -1);
	fill(cur, cur + 1 + len, 0);
	queue<int> q;
	q.push(s);
	dis[s] = 0;
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

int dfs(int u, int limit = inf) {
	if(u == t) return limit;

	int flow = 0;
	for(int i = cur[u]; i < sz(e[u]) && flow < limit; i++) {
		cur[u] = i;
		auto &[v, c, id] = e[u][i];
		if(c > 0 && dis[v] == dis[u] + 1) {
			int f = dfs(v, min(limit - flow, c));
			c -= f;
			flow += f;
			e[v][id].c += f;
		}
	}
	return flow;
}

int dinic() {
	int res = 0, f;
	while(bfs()) {
		while((f = dfs(s))) {
			res += f;
		}
	}
	return res;
}

void solve() {	
	cin >> m >> n;
	s = 0, t = m + n + 1, len = m + n + 1;
	map<int, int> mp;
	auto get = [&](int p) {
		if(mp.count(p)) return mp[p];
		return mp[p] = ++len;
	};
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		add(s, i, 1);
		for(int j = 2; j <= b[i] / j; j++) {
			if(b[i] % j == 0) {
				while(b[i] % j == 0) b[i] /= j;
				add(i, get(j), 1);
			}
		}
		if(b[i] > 1) {
			add(i, get(b[i]), 1);
		}
	}
	for(int i = 1; i <= n; i++) {
		cin >> r[i];
		add(i + m, t, 1);
		for(int j = 2; j <= r[i] / j; j++) {
			if(r[i] % j == 0) {
				while(r[i] % j == 0) r[i] /= j;
				add(get(j), i + m, 1);
			}
		}
		if(r[i] > 1) {
			add(get(r[i]), i + m, 1);
		}
	}
	cout << dinic() << '\n';
	for(int i = 0; i <= len; i++) {
		e[i].clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}