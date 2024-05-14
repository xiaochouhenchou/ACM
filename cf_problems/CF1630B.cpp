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
	思路: 对于给定的 [x, y]，需要把整个数组划分成 k 个满足条件的段，考虑构造 
		 b[i] = (x <= a[i] <= y) ? 1 : -1, s[i] = s[i - 1] + b[i]，
		 问题转化成在 s 中找长度为 k + 1 的数列 c，使得 c[i] - c[i - 1] > 0。
		 因为 |b[i] = s[i] - s[i - 1]| = 1，因此 s[i] = x 存在，x - 1 
		 也会存在于某个位置 j，且 j < i。 因此如果 s[n] >= k 的话总可以找到
		 k + 1 个数满足条件，否则不能。
		 接下来双指针，两个指针分别指向 x、y，枚举 x，移动 y 直到满足 
		 s[n] = b[1] + ... + b[n] 大于等于 k。 取所有 [x, y] 的最小值即可。

*/
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1), cnt(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] += 1;
	}
	for(int i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
	}
	auto check = [&](int x, int y) {
		int res = cnt[y] - cnt[x - 1];
		return res - (n - res) >= k;
	};
	int X = -1, Y = -1, minv = inf;
	for(int x = 1, y = 1; x <= n; x++) {
		while(y <= n && !check(x, y)) y++;
		if(y <= n && check(x, y)) {
			if(minv > y - x) {
				minv = y - x;
				X = x, Y = y;
			}
		}
	}
	vector<int> s(n + 1), mp(n + 1);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + (X <= a[i] && a[i] <= Y ? 1 : -1);
		if(s[i] >= 1 && !mp[s[i]]) {
			mp[s[i]] = i;
		}
	}
 	cout << X << ' ' << Y << '\n';
 	int l = 0;
 	for(int i = 1; i < k; i++) {
 		cout << l + 1 << ' ' << mp[i] << '\n';
 		l = mp[i];
 	}
 	cout << l + 1 << ' ' << n << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}