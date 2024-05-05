#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<int> x(n + 1), a(n + 1, 510);
	for(int i = 2; i <= n; i++) {
		cin >> x[i];
	}
	for(int i = 2; i <= n; i++) {
		a[i] = a[i - 1] + x[i];
		assert(a[i] % a[i - 1] == x[i]);
	}
	for(int i = 1; i <= n; i++) {
		cout << a[i] << " \n"[i == n];
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
	