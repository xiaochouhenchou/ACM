#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
typedef __int128 LL;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

LL n, m;

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

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if(!b) {
		x = 1, y = 0;
		return a;
	}
	LL d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

void solve() {
	n = read(), m = read();
	vector<LL> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++) {
		a[i] = read(), b[i] = read();
	}

	LL a1 = a[1], r1 = b[1];
	for(int i = 2; i <= n; i++) {
		LL a2 = a[i], r2 = b[i], k1, k2;
		LL d = exgcd(a1, a2, k1, k2);
		LL c = r2 - r1, t = a2 / d;
		if(c % d) {
			cout << "he was definitely lying\n";
			return;
		}
		k1 = c / d * k1;
		k1 = (k1 % t + t) % t;
		r1 = k1 * a1 + r1;
		a1 = a1 / d * a2;
		if(a1 < 0) {
			a1 = -a1;
		}
	}
	LL res = (r1 % a1 + a1) % a1;
	if(res > m) {
		cout << "he was probably lying\n";
	} else {
		print(res), cout << '\n';
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
