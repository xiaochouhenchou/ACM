#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 100010;

int n, m, timestmp;
int low[N], dfn[N];
vector<int> e[N];
vector<PII> bridges;

void tarjan(int p, int fa = -1) {
	dfn[p] = low[p] = ++timestmp;
	for(int q : e[p]) {
		if(!dfn[q]) {
			tarjan(q, p);
			low[p] = min(low[p], low[q]);
			if(low[q] > dfn[p]) {
				int u = p, v = q;
				if(u > v) swap(u, v);
				bridges.emplace_back(u, v);
			}
		} else if(q != fa)	// 排除从子节点到父节点的反向边
			low[p] = min(low[p], dfn[q]);
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i = 0; i < n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	sort(bridges.begin(), bridges.end());
	for(auto [x, y] : bridges) {
		cout << x << ' ' << y << '\n';
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