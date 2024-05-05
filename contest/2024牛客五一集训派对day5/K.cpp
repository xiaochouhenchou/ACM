#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> b(n + 1);
	for(int i = 1, p, x; i <= k; i++) {
		cin >> p >> x;
		b[p] = x;
	}
	for(int i = 0, j = 1; j <= n; j++) {
		if(!b[j]) continue;
		if(b[i] + j - i < b[j]) {
			cout << -1 << '\n';
			return;
		}
		i = j;
	}

	vector<vector<int>> e(n + 1);
	vector<int> stk, dg(n + 1), a(n + 1);
	for(int i = 1, j; i <= n; i++) {
		if(!b[i]) {
			if(sz(stk)) {
				e[stk.back()].push_back(i);
				dg[i] += 1;
			}
			stk.push_back(i);
			continue;
		}
		
		j = -1;
		while(sz(stk) >= b[i]) {
			j = stk.back();
			stk.pop_back();
		}
		if(sz(stk)) {
			e[stk.back()].push_back(i);
			dg[i] += 1;
		}
		stk.push_back(i);
		if(~j) {
			e[i].push_back(j);
			dg[j] += 1;
		}
	}

	{
		queue<int> q;
		for(int i = 1; i <= n; i++) {
			if(!dg[i]) {
				q.push(i);
			}
		}
		int x = 0;
		while(sz(q)) {
			int u = q.front();
			q.pop();

			a[u] = ++x;
			for(int v : e[u]) {
				if(--dg[v] == 0) {
					q.push(v);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << a[i] << " \n"[i == n];
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