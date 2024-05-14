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
	思路: 1. 枚举 l， 二分找到 l 右边第一个 r，使得 s + p[i] - p[l - 1] >= 0 
			对于 l <= i <= r 都满足，对于 i > r 不满足。 其中 p[i] 是前缀和
		 2. s + p[i] - p[l - 1] < 0，p[i] < p[l - 1] - s

*/
void solve() {
	int n, s;
	cin >> n >> s;
	vector<ll> p(n + 1), lg(n + 1);
	vector<vector<ll>> f(n + 1, vector<ll>(19));
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		p[i] += p[i - 1];
		// cout << p[i] << " \n"[i == n];
	}
	for(int i = 2; i <= n; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	for(int j = 0; j <= 18; j++) {
		for(int i = 1; i + (1 << j) - 1 <= n; i++) {
			if(!j) f[i][j] = p[i];
			else {
				f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	auto query = [&](int l, int r) {
		int k = lg[r - l + 1];
		return min(f[l][k], f[r - (1 << k) + 1][k]);
	};
	int maxv = -inf, i = -1, j = -1;
	for(int l = 1; l <= n; l++) {
		int low = l, high = n;
		while(low < high) {
			int mid = (low + high + 1) / 2;
			if(query(l, mid) >= p[l - 1] - s) {
				low = mid;
			} else {
				high = mid - 1;
			}
		}
		if(query(l, high) >= p[l - 1] - s) {
			if(maxv < high - l + 1) {
				maxv = high - l + 1;
				i = l, j = high;
			}
		}
	}
	if(i == -1) cout << -1 << '\n';
	else cout << i << ' ' << j << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}