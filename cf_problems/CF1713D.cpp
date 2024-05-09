#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<int> v1(1 << n), v2(1 << n);
	iota(v1.begin(), v1.end(), 1);
	auto ask1 = [&](int a, int b) {
		cout << "? " << a << ' ' << b << endl;
		int x;
		cin >> x;
		return x;
	};
	/*
		a > b: 1
		a < b: 2
		a = b: 0
	*/
	auto ask2 = [&](int a, int b, int c, int d) {
		int x = ask1(a, c);
		if(x == 0) {	// a = c
			int y = ask1(b, d);
			return (y <= 1 ? b : d);	// b >= d, y <= 1
		} else {
			if(x == 1) {	// a > c
				int y = ask1(a, d);
				return (y <= 1 ? a : d);
			} else {
				int y = ask1(b, c);
				return (y <= 1 ? b : c);
			}
		}
	};
	while(n >= 2) {
		int c = 0;
		for(int i = 0; i < (1 << n); i += 4) {
			v2[c++] = ask2(v1[i], v1[i + 1], v1[i + 2], v1[i + 3]);
		}
		for(int i = 0; i < c; i++) {
			v1[i] = v2[i];
		}
		n -= 2;
	}
	int ans = v1[0];
	if(n == 1) {
		if(ask1(v1[0], v1[1]) == 2) {
			ans = v1[1];
		}
	}
	cout << "! " << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}