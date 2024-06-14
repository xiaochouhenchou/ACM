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
int dfn[N], low[N], Size[N];
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
		int cur;
		scc_cnt += 1;
		do {
			cur = stk.back();
			stk.pop_back();
			in_stk[cur] = false;
			Size[scc_cnt] += 1;
		} while(cur != u);
	}
}

void solve() {
	cin >> n >> m;
	while(m--) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
	}
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	int ans = 0;
	for(int i = 1; i <= scc_cnt; i++) {
		ans += Size[i] > 1;
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