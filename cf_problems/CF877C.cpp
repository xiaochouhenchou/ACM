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
	int op = n / 2 * 2 + n - n / 2;
	cout << op << '\n';
	for(int i = 2; i <= n; i += 2)
		cout << i << ' ';
	for(int i = 1; i <= n; i += 2)
		cout << i << ' ';
	for(int i = 2; i <= n; i += 2)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}