#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

// typedef long long LL;
typedef __int128 LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const double eps = 1e-8;
const int mod = 1e9 + 7;

LL read() {
	string s;
	cin >> s;
	LL res = 0;
	for(char c : s) {
		res = res * 10 + c - '0';
	}
	return res;
}

void print(LL x) {
	if(x / 10) print(x / 10);
	cout << int(x % 10);
}

LL my_pow(LL x, LL k) {
	LL res = 1;
	while(k--) res *= x;
	return res;
}

void solve() {
	LL n = read(), k = read();
	LL ans = 0, m = ceil(pow(n, 1.0 / (1.0 * k)));
	LL up = ceil(pow(n, 1.0 / (1.0 * (k - 1))));
	for(LL t = 1; t <= min(n, m); t++) {
		if(n % t) continue;

		LL l = 1, r = up;
		while(l < r) {
			LL mid = (l + r) / 2;
			if(my_pow(mid + t, k) - my_pow(mid, k) >= n) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}

		if(my_pow(r + t, k) - my_pow(r, k) == n) {
			// print(r + t), cout << ' ', 
			// print(r), cout << '\n';
			ans += 1;
		}
	}
	print(ans), cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;	
	while(t--) {
		solve();
	}
	return 0;
}
