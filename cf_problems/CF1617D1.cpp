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
	思路: n / 3 < k < 2n / 3，那么可以问一遍 n 个相邻的三个数 (i, i + 1, i + 1)，
		 必定存在两个相邻的询问 (a, b, c) != (b, c, d)，即 a != d。 这样可以知道
		 a 和 d 的身份，接下来再问剩下的 n - 2 个人的身份即可。询问次数 2n - 2
*/

void solve() {
	int n;
	cin >> n;
	auto ask = [&](int a, int b, int c) {
		cout << "? " << a << ' ' << b << ' ' << c << endl;
		int x;
		cin >> x;
		return x;
	};
	vector<int> v(n), ans(n + 1, -1);
	for(int i = 0; i < n; i++) {
		int a = i;
		int b = (a + 1) % n;
		int c = (b + 1) % n;
		v[i] = ask(a + 1, b + 1, c + 1);
	}
	int a = -1, d = -1;
	for(int i = 0; i < n; i++) {
		if(v[i] != v[(i + 1) % n]) {
			a = i + 1, d = (i + 3) % n + 1;
			if(v[i] == 0) {
				ans[a] = 0, ans[d] = 1;
			} else {
				ans[a] = 1, ans[d] = 0;
			}
			break;
		}
	}
	int k = 0;
	for(int i = 1; i <= n; i++) {
		if(ans[i] == -1) {
			ans[i] = ask(a, d, i);
		}
		k += !ans[i];
	}
	cout << "! " << k;
	for(int i = 1; i <= n; i++) {
		if(ans[i] == 0) {
			cout << " " << i;
		}
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}