#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 10010, M = 100010;

int n, m;
int p[N];
struct edge {
	int u, v, w;
	bool operator < (const edge &e) const {
		return w < e.w;
	}
}e[M];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

int kruskal() {
	sort(e, e + m);
	iota(p, p + n, 0);
	int res = 0;
	for(int i = 0; i < m; i++) {
		auto [u, v, w] = e[i];
		if(find(u) != find(v)) {
			p[find(u)] = find(v);
			res += w;
		}
	}
	return res;
}

void solve() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	cout << kruskal() << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}