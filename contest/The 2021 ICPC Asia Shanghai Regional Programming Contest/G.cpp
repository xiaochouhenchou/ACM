#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 100010;

int n;
int f[N], g[N], cnt[N];
vector<int> e[N];

void dfs(int u, int fa) {
	cnt[u] = 1;
	int a = 0, res = 1;
	for(int v : e[u]) {
		if(v ==fa) continue;

		dfs(v, u);
		cnt[u] += cnt[v];
		a += (cnt[v] & 1);
		res = 1ll * res * g[v] % mod;
	}
	if(a & 1) a += 1;
	g[u] = 1ll * res * f[a] % mod;
}

void solve() {
	cin >> n;
	f[0] = 1;
	for(int i = 2; i <= n; i += 2) {
		f[i] = 1ll * f[i - 2] * (i - 1) % mod;
	}
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	cout << g[1] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}