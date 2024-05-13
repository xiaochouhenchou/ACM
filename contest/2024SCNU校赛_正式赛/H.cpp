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
	思路： 
		yes 的条件： 
			1. k 出现在 a 中 
			2.1 k 和一个大于等于 k 的数相邻，可以两个两个操作最后全部变成 k。
			2.2 k 左边或者右边（不包括 k) 有连续三个数满足其中 >= k 的
				数有至少两个。 满足这个条件的话可以把 k 的一侧全部变成 >= k 
				的数，然后从 k 开始两个两个操作可以把这一侧的数全变成 k，最后
				再把另外一侧变成 k。
			2.1 和 2.2 满足一个即可。
*/

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	int ok = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		ok |= a[i] == k;
	}
	if(!ok) {
		cout << "no\n";
		return;
	}
	if(n == 1) {
		cout << "yes\n";
		return;
	}

	for(int i = 1; i <= n; i++) {
		if(a[i] == k) {
			if(i - 1 >= 1 && a[i - 1] >= k) {
				cout << "yes\n";
				return;
			}
			if(i + 1 <= n && a[i + 1] >= k) {
				cout << "yes\n";
				return;
			}
		}
	}

	vector<int> pre(n + 2), suf(n + 2);
	for(int i = 3; i <= n; i++) {
		int cnt = 0;
		if(a[i - 2] >= k) cnt += 1;
		if(a[i - 1] >= k) cnt += 1;
		if(a[i] >= k) cnt += 1;
		pre[i] = pre[i - 1] | (cnt >= 2);
	}
	for(int i = n - 2; i; i--) {
		int cnt = 0;
		if(a[i] >= k) cnt += 1;
		if(a[i + 1] >= k) cnt += 1;
		if(a[i + 2] >= k) cnt += 1;
		suf[i] = suf[i + 1] | (cnt >= 2);
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] == k) {
			if(pre[i - 1] || suf[i + 1]) {
				cout << "yes\n";
				return;
			}
		}
	}
	cout << "no\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}