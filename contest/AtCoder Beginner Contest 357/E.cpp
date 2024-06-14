#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 200010;

int n, dfn[N], low[N], timestmp;
int scc_cnt, id[N], dg[N];
bool in_stk[N];
vector<int> e[N], scc[N], stk;
ll f[N];

void tarjan(int u) {
	low[u] = dfn[u] = ++timestmp;
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
			scc[scc_cnt].push_back(cur);
		} while(cur != u);
	}
}

void solve() {
	cin >> n;
	for(int i = 1, a; i <= n; i++) {
		cin >> a;
		e[i].push_back(a);
	}
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1; i <= n; i++) {
		f[i] = sz(scc[id[i]]);
	}
	for(int i = 1; i <= scc_cnt; i++) {
		for(int u : scc[i]) {
			for(int v : e[u]) {
				if(id[v] < id[u]) {
					f[u] += f[v];
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += f[i];
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