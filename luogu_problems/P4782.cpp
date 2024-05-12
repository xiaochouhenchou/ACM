#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 2000010;

int n, m;
int low[N], dfn[N], timestmp;
int scc_cnt, id[N];
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
	x:  x
	!x: x + n
*/
void solve() {
	cin >> n >> m;
	while(m--) {
		int i, a, j, b;
		cin >> i >> a >> j >> b;
		if(a && b) {	// a v b <-> !a -> b ^ !b -> a
			e[i + n].push_back(j);
			e[j + n].push_back(i);
		} else if(a && !b) {	// a v !b <-> !a -> !b ^ b -> a
			e[i + n].push_back(j + n);
			e[j].push_back(i);
		} else if(!a && b) {	// !a v b <-> a -> b ^ !b -> !a
			e[i].push_back(j);
			e[j + n].push_back(i + n);
		} else {	// !a v !b <-> a -> !b ^ b -> !a
			e[i].push_back(j + n);
			e[j].push_back(i + n);
		}
	}
	for(int i = 1; i <= n * 2; i++) {
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1; i <= n; i++) {
		if(id[i] == id[i + n]) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}

	cout << "POSSIBLE\n";
	// 编号 scc_cnt -> 1 是拓扑序的顺序
	// !x -> x，如果 x 的拓扑序大于 !x 的拓扑序，x 赋值 1，否则赋值 0
	for(int i = 1; i <= n; i++) {
		cout << (id[i] < id[i + n]) << " \n"[i == n];
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