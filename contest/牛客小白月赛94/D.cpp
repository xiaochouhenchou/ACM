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
	vector<int> a(n + 1), p(n + 1), vis(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i + 1 <= n; i++) {
		if(a[i] % a[i + 1]) {
			cout << -1 << '\n';
			return;
		}
	}
	for(int i = 1; i <= n; ) {
		int j = i + 1;
		while(j <= n && a[j] == a[i]) j += 1;
		int x = a[i];
		for(int k = i; k < j; k++) {
			while(x <= n && vis[x]) {
				x += a[i];
			}
			if(x > n) {
				cout << -1 << '\n';
				return;
			}
			p[k] = x;
			vis[x] = 1;
			x += a[i];
		}
		i = j;
	}

	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			cout << -1 << '\n';
			return;
		}
	}
	int g = 0;
	for(int i = 1; i <= n; i++) {
		g = __gcd(g, p[i]);
		if(g != a[i]) {
			cout << -1 << '\n';
			return;
		}
	}

	for(int i = 1; i <= n; i++) {
		cout << p[i] << " \n"[i == n];
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