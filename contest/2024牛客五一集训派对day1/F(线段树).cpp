#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 100010, M = 300010;

/*
	思路：
		1. 对列建立线段树, 线段树叶子节点表示第 j, j + r, j + 2r 列的气球数量和。
		2. 枚举选第 x, x + r, x + 2r 行，将这些行上的气球全部删除，更新线段树，
		   接着查询整棵线段树的最大值。
		3. 将删除的气球插入回去，枚举下一行。
	时间复杂度：
		令 N = 1e5, n = 气球数量
		建树 O(NlogN)，枚举所有行 O(N)，每一行的气球删除三次，插入三次，即 O(6nlogn)
		总复杂度为 O(NlongN + N + 6nlogn)
*/

int c[M], r[M], n, dis, m = 1e5;
vector<int> row[M];
struct node {
	int v;
}tr[M * 4];

void pushup(int u) {
	tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r) {
	tr[u] = {c[r] + c[r + dis] + c[r + dis * 2]};
	if(l == r) return;
	int mid = (l + r) / 2;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void update(int u, int l, int r, int pos, int v) {
	if(l == r) {
		tr[u].v += v;
		return;
	}
	int mid = (l + r) / 2;
	if(pos <= mid) update(u << 1, l, mid, pos, v);
	else update(u << 1 | 1, mid + 1, r, pos, v);
	pushup(u);
}

// 包含第 j 列的节点有： j - 2dis, j - dis, j
void update(int j, int val) {
	for(int i = -2; i <= 0; i++) {
		if(j + i * dis < 0 || j + i * dis > m) continue;
		update(1, 0, m, j + i * dis, val);
	}
}

void solve() {
	cin >> n >> dis;
	for(int i = 1, x, y; i <= n; i++) {
		cin >> x >> y;
		c[y] += 1;
		r[x] += 1;
		row[x].push_back(y);
	}

	int ans = 0;
	build(1, 0, m);
	for(int x = 0; x <= m; x++) {
		int res = 0;
		for(int j = 0; j < 3; j++) {
			res += r[x + j * dis];
			for(int y : row[x + j * dis]) {
				update(y, -1);
			}
		}

		res += tr[1].v;
		ans = max(ans, res);

		for(int j = 0; j < 3; j++) {
			for(int y : row[x + j * dis]) {
				update(y, 1);
			}
		}		
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;	
}
