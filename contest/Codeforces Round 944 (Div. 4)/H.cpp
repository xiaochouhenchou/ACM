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

int n;
int low[N], dfn[N], timestmp;
int id[N], scc_cnt;
bool in_stk[N];
vector<int> e[N], g[3], stk;

void init() {
	timestmp = scc_cnt = 0;
	for(int i = 1; i <= n * 2; i++) {
		low[i] = dfn[i] = id[i] = 0;
		e[i].clear();
	}
}

void tarjan(int u) {
	dfn[u] = low[u] = ++timestmp;
	stk.push_back(u);
	in_stk[u] = true;
	for(int v : e[u]) {
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(in_stk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]) {
		scc_cnt += 1;
		int cur;
		do {
			cur = stk.back();
			stk.pop_back();
			in_stk[cur] = false;
			id[cur] = scc_cnt;
		} while(cur != u);
	}
}

/*
	-1: false
	1: true
*/

void solve() {
	cin >> n;
	init();
	for(int i = 0; i < 3; i++) {
		g[i].resize(n + 1);
		for(int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}
	auto get = [&](int x) {
		return x < 0 ? -x + n : x;
	};
	for(int j = 1; j <= n; j++) {
		int x = g[0][j];
		int y = g[1][j];
		int z = g[2][j];
		e[get(-x)].push_back(get(y));
		e[get(-x)].push_back(get(z));
		e[get(-y)].push_back(get(x));
		e[get(-y)].push_back(get(z));
		e[get(-z)].push_back(get(x));
		e[get(-z)].push_back(get(y));
	}
	
	for(int i = 1; i <= n * 2; i++) {
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1; i <= n; i++) {
		if(id[i] == id[i + n]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}