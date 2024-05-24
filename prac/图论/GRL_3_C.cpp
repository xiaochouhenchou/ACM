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

int n, m, timestmp, scc_cnt;
int low[N], dfn[N], id[N];
bool in_stk[N];
vector<int> e[N], stk;

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
		++scc_cnt;
		int cur;
		do {
			cur = stk.back();
			stk.pop_back();
			in_stk[cur] = false;
			id[cur] = scc_cnt;
		} while(cur != u);
	}
}

void solve() {
	cin >> n >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	for(int i = 0; i < n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << (id[u] == id[v]) << '\n';
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