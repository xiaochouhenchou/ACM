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

int n, m, s, pt, t, cnt, pre[N];
int vis[N], c[N];
vector<int> e[N];

void dfs(int u, int fa, int col) {
	pre[u] = fa;
	c[u] = col;
	vis[u] = 1;
	if(!fa) {
		int idx = 0;
		for(int v : e[u]) {
			if(!vis[v]) {
				dfs(v, u, ++idx);
			}
		}		
	} else {
		for(int v : e[u]) {
			if(!vis[v]) {
				dfs(v, u, col);
			}
		}
	}
}

void dfs(int u, int fa) {
	cout << u << ' ' << fa << ' ' << c[u] << '\n';
	if(t) return;
	for(int v : e[u]) {
		if(c[v] != c[u]) {	// u、 v 来自不同子树
			
		}
		dfs(v, u);
	}
}

void solve() {
	cin >> n >> m >> s;
	while(m--) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	dfs(s, 0, 0);
	dfs(s, 0);

	if(!t) {
		cout << "Impossible\n";
		return;
	}
	
	vector<int> v1, v2;
	{
		int cur = pt;
		v1.push_back(t);
		while(cur) {
			v1.push_back(cur);
			cur = pre[cur];
		}
	}
	{
		int cur = t;
		while(cur) {
			v2.push_back(cur);
			cur = pre[cur];
		}
	}
	cout << "Possible\n";
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());
	cout << sz(v1) << '\n';
	for(int i = 0; i < sz(v1); i++) {
		cout << v1[i] << " \n"[i == sz(v1) - 1];
	}
	cout << sz(v2) << '\n';
	for(int i = 0; i < sz(v2); i++) {
		cout << v2[i] << " \n"[i == sz(v2) - 1];
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