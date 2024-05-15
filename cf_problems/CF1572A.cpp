#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

/*
	思路: 拓扑排序。 从当前的书需要先阅读的所有书向当前的书连边。如果有环的话
		 答案为 -1。 否则用队列维护入度为 0 的点，一次拓展可以
		 拓展 [1, n] 中位于队列中的点。
*/

void solve() {
	int n;		
	cin >> n;
	vector<vector<int>> e(n + 1);
	vector<int> dg(n + 1);
	for(int i = 1, k, a; i <= n; i++) {
		cin >> k;
		while(k--) {
			cin >> a;
			e[a].push_back(i);
			dg[i] += 1;
		}
	}
	int ans = 0;
	set<int> q;
	for(int i = 1; i <= n; i++) {
		if(!dg[i]) q.emplace(i);
	}
	while(sz(q)) {
		ans += 1;
		int last = 0;
		while(sz(q)) {
			auto it = q.upper_bound(last);
			if(it == q.end()) {
				break;
			}
			int u = *it;
			last = u;
			q.erase(it);

			for(int v : e[u]) {
				if(--dg[v] == 0) q.emplace(v);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(dg[i]) {
			cout << -1 << '\n';
			return;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}