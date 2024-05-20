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
	思路: 注意操作的性质，x 只会与比它大的数 a[i] 交换，因此操作之后 x 
		 会变大。 如果遇到乱序且可以操作的位置，我们一定是从左往右操作。
		 如果不是从左往右操作的话，假如本应该操作 i 却操作了 j，i < j，
		 那么结果使得 a[i] > a[j]，不能使得序列最终有序。因此找到最后
		 一个乱序的位置，从左往右能操作就操作，最后判断序列是否有序即可。

*/
void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = max(pre[i - 1], a[i]);
	}
	int last = -1;
	for(int i = 2; i <= n; i++) {
		if(pre[i - 1] > a[i]) {
			last = i;
		}
	}
	if(last == -1) {
		cout << 0 << '\n';
		return;
	}

	int ans = 0;
	for(int i = 1; i <= last; i++) {
		if(a[i] > x) {
			swap(a[i], x);
			ans += 1;
		}
	}
	for(int i = 1; i + 1 <= n; i++) {
		if(a[i] > a[i + 1]) {
			cout << -1 << '\n';
			return;
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