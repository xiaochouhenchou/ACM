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
	string s;
	cin >> s;
	int n = sz(s);
	s = " " + s + s;
	vector<int> h(n * 2 + 1);
	int p = 1;
	for(int i = 0; i < n; i++) {
		p = p * 10 % 4;
	}
	for(int i = 1; i <= n * 2; i++) {
		h[i] = (h[i - 1] * 10 + s[i] - '0') % 4;
	}
	for(int i = n; i <= n * 2; i++) {
		int res = (h[i] - h[i - n] * p % 4) % 4;
		res = (res + 4) % 4;
		if(!res) {
			cout << i - n << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}