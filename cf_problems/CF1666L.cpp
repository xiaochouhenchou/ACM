#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 300010;

int n, m, s;
int c[N], pre[N];
vector<int> e[N];

// s -> ... -> pt -> t
// s -> ... -> t
void print_ans(int t, int pt) {
	vector<int> v1, v2{t};
	while(t) {
		v1.push_back(t);
		t = pre[t];
	}
	while(pt) {
		v2.push_back(pt);
		pt = pre[pt];
	}
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());
	cout << "Possible\n";
	cout << sz(v1) << '\n';
	for(int i = 0; i < sz(v1); i++) {
		cout << v1[i] << " \n"[i == sz(v1) - 1];
	}
	cout << sz(v2) << '\n';
	for(int i = 0; i < sz(v2); i++) {
		cout << v2[i] << " \n"[i == sz(v2) - 1];
	}
	exit(0);
}

void dfs(int u, int fa, int start) {
	if(u == s) return;
	// u 就是所求的 t，在起点为 start 的子树里遇到了起点不同的 u
	if(c[u]) {	
		if(c[u] != start) {
			print_ans(u, fa);
		}
		return;
	}
	
	c[u] = start;
	pre[u] = fa;
	for(int v : e[u]) {
		dfs(v, u, start);
	}
}

void solve() {
	cin >> n >> m >> s;
	while(m--) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	}

	for(int v : e[s]) {
		dfs(v, s, v);
	}

	cout << "Impossible\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}