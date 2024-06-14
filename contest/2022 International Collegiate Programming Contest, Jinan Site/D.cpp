#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 20;

int m, a, b, cnt, n, X[N], Y[N];
int type[N], x[N], y[N];
int arr[N];

bool check() {
	int l = 0, r = 0;
	for(int i = 0; i < n; i++) {
		int idx = arr[i];
		// cout << idx << " \n"[i == n - 1];
		l += (y[idx] - x[idx]) * 20 + 240;
		r += (y[idx] - 1) * 20 + 299;
	}

	if(b < l || b > r) return false;

	// cout << b << '\n';
	b -= l;
	for(int i = 0; i < n; i++) {
		int idx = arr[i];
		type[idx] = 4;
		int k = min(b / 20, x[idx] - 1);		// 封榜后的提交次数减1
		b -= k * 20;
		int tmp = min(b, 59);
		x[idx] = k + 1 + y[idx] - x[idx];
		y[idx] = 240 + tmp;
		b -= tmp;
	}
	
	return true;
}

/*
	type[i]:
	1 -> '.'
	2 -> '-'
	3 -> '?'
	4 -> '+'
*/
void solve() {
	cin >> a >> b;
	cnt = a;
	for(int i = 0; i < m; i++) {
		string c, s;
		cin >> c;
		x[i] = y[i] = 0;
		if(c[0] == '.') {
			type[i] = 1;
		} 
		if(c[0] == '-') {
			type[i] = 2;
			cin >> x[i];
		}
		if(c[0] == '?') {
			type[i] = 3;
			cin >> x[i] >> y[i];
		}
		if(c[0] == '+') {
			type[i] = 4;
			cin >> s;
			for(int j = 0, ok = 0; j < sz(s); j++) {
				if(s[j] == '/') {
					ok = 1;
					continue;
				}
				if(!ok) x[i] = x[i] * 10 + s[j] - '0';
				else {
					y[i] = y[i] * 10 + s[j] - '0';
				}
			}
			cnt -= 1;
			b -= y[i] + (x[i] - 1) * 20;
		}
		// cout << type[i] << ' ' << x[i] << ' ' << y[i] << '\n';
	}
	if(cnt < 0 || b < 0) {
		cout << "No\n";
		return;
	}
	// cout << cnt << ' ' << b << '\n';

	int ok = 0;
	for(int i = 0; i < (1 << m); i++) {
		int can = 1;
		n = 0;
		for(int j = 0; j < m; j++) {
			if(!(i >> j & 1)) continue;
			if(type[j] != 3) {
				can = 0;
				break;
			}
			arr[n++] = j;
		}
		can &= (n == cnt);
		if(!can) continue;

		if(check()) {
			ok = 1;
			break;
		}
	}

	if(!ok) {
		cout << "No\n";
	} else {
		// cout << b << '\n';
		cout << "Yes\n";
		for(int i = 0; i < m; i++) {
			if(type[i] == 1) {
				cout << ".\n";
			}
			if(type[i] == 2) {
				cout << "- " << x[i] << '\n';
			}
			if(type[i] == 3) {
				cout << "- " << y[i] << '\n';
			}
			if(type[i] == 4) {
				cout << "+ " << x[i] << '/' << y[i] << '\n';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t >> m;
	while(t--) solve();
	return 0;
}