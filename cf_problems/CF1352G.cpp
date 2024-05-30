#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// 分奇偶构造
void solve() {
	int n;
	cin >> n;
	if(n <= 3) {
		cout << -1 << '\n';
		return;
	}
	vector<int> a(n);
	int idx = 0;
	for(int i = n - (n % 2 == 0); i > 0; i -= 2) {
		a[idx++] = i;
	}
	a[idx++] = 4;
	a[idx++] = 2;
	for(int i = 6; idx < n; i += 2) {
		a[idx++] = i;
	}
	for(int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}