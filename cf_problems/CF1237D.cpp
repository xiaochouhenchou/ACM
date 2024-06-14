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

int n, a[N], ans[N];
int next_ge[N], next_le[N];

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = n + 1; i <= n * 2; i++) {
		a[i] = a[i + n] = a[i - n];
	}
	{
		vector<int> stk;
		for(int i = n * 3; i; i--) {
			while(sz(stk) && a[stk.back()] <= a[i]) stk.pop_back();
			next_ge[i] = inf;
			if(sz(stk)) {
				next_ge[i] = stk.back();
			}
			stk.push_back(i);
		}
	}
	{
		vector<int> stk;
		for(int i = n * 3; i; i--) {
			while(sz(stk) && a[stk.back()] >= a[i]) stk.pop_back();
			next_le[i] = inf;
			if(sz(stk)) {
				int l = 0, r = sz(stk) - 1;
				while(l < r) {
					int mid = (l + r + 1) / 2;
					if(a[stk[mid]] * 2 < a[i]) l = mid;
					else r = mid - 1;
				}
				if(a[stk[r]] * 2 < a[i]) {
					next_le[i] = stk[r];
				}
			}
			stk.push_back(i);
		}
	}

	// for(int i = 1; i <= n * 3; i++) {
	// 	cout << a[i] << " \n"[i == n * 3];
	// }
	// for(int i = 1; i <= n * 3; i++) {
	// 	cout << next_ge[i] << " \n"[i == n * 3];
	// }
	// for(int i = 1; i <= n * 3; i++) {
	// 	cout << next_le[i] << " \n"[i == n * 3];
	// }

	auto dfs = [&](auto dfs, int i) -> int {
		if(ans[i] != 0) return ans[i];
		int j = next_ge[i];
		int k = next_le[i];
		if(j < k) {
			return ans[i] = dfs(dfs, j) + j - i;
		}
		return ans[i] = k - i;
	};
	
	for(int i = 1; i <= n * 3; i++) {
		if(!ans[i]) {
			dfs(dfs, i);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(ans[i] >= inf / 2) ans[i] = -1;
		cout << ans[i] << " \n"[i == n];
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