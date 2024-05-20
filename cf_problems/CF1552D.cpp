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
	思路: 假设一个有向图，每个点的点权为 b[i]，其中 j -> k 的边权
		 为 a[i]，k -> j 的边权为 -a[i]。 （如果存在 
		 b[j] - b[k] = a[i] 必定存在 b[k] - b[j] = -a[i]）
		 这样这个有向图相当于一个无向图。 由题意知道图中有 n 个点和
		 n 条无向边，那么其中必定存在环。假设环的大小为 m，环上的点为
		 i1,i2,...,im，使得 (b[i1] - b[i2]) + (b[i2] - b[i3])
		 + ... + (b[im] - b[i1]) = 0。 将括号替换成对应边权 +a[i]
		 或 -a[i]，那么可以知道必定存在 s1 * a[i1] + ... + sm * a[im]
		 = 0，其中 si = 1 或者 si = -1。 因此枚举 a 的所有子集，这些子集
		 的元素取正或者取负的和为 0 即有解。时间复杂度 O(3^n)
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	auto dfs = [&](auto dfs, int u, int sum, int cnt) -> bool {
		if(u == n + 1) {
			return !sum && cnt;
		}

		if(dfs(dfs, u + 1, sum, cnt)) return true;
		if(dfs(dfs, u + 1, sum + a[u], cnt + 1)) return true;
		if(dfs(dfs, u + 1, sum - a[u], cnt + 1)) return true;
		return false;
	};
	cout << (dfs(dfs, 1, 0, 0) ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}