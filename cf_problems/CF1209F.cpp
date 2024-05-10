#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 100010, M = 10 * N;

/*
	思路: 把 m 条边拆成 mlogm 条边，每条边按照编号的十进制位数拆，如 4 <-> 5
		 的编号为 12，就拆成 4 <-> x <-> 5，其中 4 <-> x 权值为 1，
		 x <-> 5 权值为 2。 这样原问题转化成求 dag 上求字典序最小的路径的问题。
		 这个问题可以在 BFS 的时候优先选择边权小的边即可。需要注意的是，对于距离相同
		 的同一个集合中的点，我们需要同时用其中的点去更新其他点。
*/

int dis[M];
vector<int> e[M][10];

// x -> y, w
void add(int x, int y, int w) {
	e[x][w].push_back(y);
	// cout << x << ' ' << y << ' ' << w << '\n';
}

void solve() {
	int n, m;
	cin >> n >> m;
	int idx = n;
	vector<int> vec;
	for(int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		string s = to_string(i);
		vec.clear();
		for(int j = 0; j + 1 < sz(s); j++) {
			vec.push_back(idx + j + 1);
		}

		int x = u;
		for(int j = 0; j + 1 < sz(s); j++) {
			add(x, vec[j], s[j] - '0');
			x = vec[j];
		}
		add(x, v, s.back() - '0');

		int y = v;
		reverse(vec.begin(), vec.end());
		for(int j = 0; j + 1 < sz(s); j++) {
			add(y, vec[j], s[j] - '0');
			y = vec[j];
		}
		add(y, u, s.back() - '0');
		idx += sz(s) - 1;
	}

	// bfs
	{
		fill(dis + 1, dis + 1 + idx + n, -1);
		queue<vector<int>> q;
		vector<vector<int>> a(10);
		dis[1] = 0;
		q.push(vector<int>{1});
		while(sz(q)) {
			auto st = q.front();
			q.pop();

			for(int i = 0; i < 10; i++) {
				a[i].clear();
				for(int u : st) {
					for(int v : e[u][i]) {
						if(dis[v] == -1) {
							dis[v] = (10ll * dis[u] + i) % mod;
							a[i].push_back(v);
						}
					}
				}
				if(sz(a[i])) {
					q.push(a[i]);
				}
			}
		}
	}
	for(int i = 2; i <= n; i++) {
		cout << dis[i] << "\n";
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