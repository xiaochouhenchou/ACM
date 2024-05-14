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
	思路: 最小值最大问题，考虑二分解决。 n 个人从 n - 1 间商店买礼物，根据鸽巢原理，必定至少
		 有两个人从同一家商店买东西。因此 check() 函数中检查： 
		 	1. 每个人是否都能买到 >= mid 的礼物
		 	2. 是否有一家商店满足给至少两个人买到 >= mid 的礼物

*/

void solve() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> a(m + 1, vector<int>(n + 1));
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	// 能否 >= mid
	auto check = [&](int mid) {
		for(int j = 1; j <= n; j++) {
			int ok = 0;
			for(int i = 1; i <= m; i++) {
				if(a[i][j] >= mid) {
					ok = 1;
					break;
				}
			}
			if(!ok) return false;
		}
		for(int i = 1; i <= m; i++) {
			int c = 0;
			for(int j = 1; j <= n; j++) {
				c += (a[i][j] >= mid);
			}
			if(c >= 2) return true;
		}
		return false;
	};
	int l = 1, r = inf;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << r << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}