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
	int n, a;
	cin >> n >> a;
	int last = 0;
	for(int i = 0, t; i < n; i++) {
		cin >> t;
		int cur = max(last, t) + a;
		cout << cur << '\n';
		last = cur;
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