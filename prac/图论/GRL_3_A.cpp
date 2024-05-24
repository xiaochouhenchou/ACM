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

int n, m;
int low[N], dfn[N], timestmp;
vector<int> e[N], cut;

void tarjan(int p, int is_root = 1) {
	dfn[p] = low[p] = ++timestmp;
	int cnt = 0;
	for(int q : e[p]) {
		if(!dfn[q]) {
			tarjan(q, 0);
			low[p] = min(low[p], low[q]);
			cnt += (low[q] >= dfn[p]);
		} else {
			low[p] = min(low[p], dfn[q]);
		}
	}
	if(cnt > is_root) {	// 如果是根节点 cnt 需要大于 1
		cut.push_back(p);
	}
}

void solve() {
	cin >> n >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i = 0; i < n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	sort(cut.begin(), cut.end());
	for(int x : cut) {
		cout << x << '\n';
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