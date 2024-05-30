#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// 构造...
void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(n == 1) {
		cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n' << -a[1] << '\n';
		return;
	}

	cout << 1 << ' ' << 1 << '\n' << -a[1] << '\n';
	cout << 1 << ' ' << n << '\n' << 0;
	for(int i = 2; i <= n; i++) {
		cout << ' ' << -1ll * n * a[i];
	}
	cout << '\n';
	cout << 2 << ' ' << n << '\n';
	for(int i = 2; i <= n; i++) {
		cout << 1ll * (n - 1) * a[i] << " \n"[i == n];
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