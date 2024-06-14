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

int n, timestmp, scc_cnt;
int dfn[N], low[N], id[N], in[N], out[N];
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
			id[cur] = scc_cnt;
			in_stk[cur] = false;
		} while(cur != u);
	}
}

void solve() {
	cin >> n;
	for(int i = 1, x; i <= n; i++) {
		while(cin >> x, x) {
			e[i].push_back(x);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) tarjan(i);
 	}
 	for(int u = 1; u <= n; u++) {
 		for(int v : e[u]) {
 			if(id[u] != id[v]) {
 				out[id[u]] += 1;
 				in[id[v]] += 1;
 			}
 		}
 	}
 	int cnt1 = 0, cnt2 = 0;
 	for(int i = 1; i <= scc_cnt; i++) {
 		if(!in[i]) {
 			cnt1 += 1;
 		}
 		if(!out[i]) {
 			cnt2 += 1;
 		}
 	}
 	cout << cnt1 << '\n';
 	if(scc_cnt == 1) cout << 0 << '\n';
 	else cout << max(cnt1, cnt2) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}