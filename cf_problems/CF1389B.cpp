#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// f[i][j] 表示位于第 i 个位置时已经往左走了 j 次的最大分数
// f[i][j] = max(f[i - 1][j], f[i + 1][j - 1]) + a[i]
void solve() {
	int n, k, z;
	cin >> n >> k >> z;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> f(n + 1, vector<int>(z + 1));
	int ans = 0;
	for(int j = 0; j <= z; j++) {
		for(int i = 1; i <= n; i++) {
			f[i][j] = max(f[i][j], f[i - 1][j] + a[i]);
			if(i + 1 <= n && j) {
				f[i][j] = max(f[i][j], f[i + 1][j - 1] + a[i]);
			}
			if(i - 1 + j * 2 == k) {
				ans = max(ans, f[i][j]);
			}
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