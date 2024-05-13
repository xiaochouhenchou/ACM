#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// 返回 x 的二进制表示中最后一位 1 的幂
int lowbit(int x) { return x & -x; }

/*
	思路: dag 图的全部子图都满足至少有一个节点入度为 0，那么考虑状压dp，
		 f[i] 表示让由 i 的二进制表示中的 1 组成的子图变成 dag 的最小
		 花费。 r[i] 这个数的二进制中 1 表示 i 这个节点的入边起点的集合。
		 枚举 i 的二进制表示中的 1 的位置 j，如果让 j 的入度变为 0，
		 那么 f[i] = min(f[i], f[i ^ (1 << j)] + (r[j] & i)中 1 的个数)，
		 其中 (r[j] & i) 表示 j 这个节点的入边起点和子图 i 的交集，i 这个子图
		 变成 dag 的花费等于 i ^ (1 << j) 这个子图的花费加上把 (r[j] & i) 中的点
		 到 j 的边移除的花费的最小值。 最终答案即为 f[(1 << n) - 1]。
*/

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> f(1 << n, inf);
	vector<int> lg2(1 << n), r(n);
	for(int i = 2; i < (1 << n); i++) {
		lg2[i] = lg2[i / 2] + 1;
	}
	while(m--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		r[v] |= 1 << u;
	}

	f[0] = 0;
	for(int i = 1; i < (1 << n); i++) {
		int x = i;
		while(x) {
			int j = lg2[lowbit(x)];
			f[i] = min(f[i], f[i ^ (1 << j)] + __builtin_popcount(r[j] & i));
			x -= lowbit(x);
		}
	}
	cout << f[(1 << n) - 1] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}