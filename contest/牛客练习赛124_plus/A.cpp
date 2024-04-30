#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 4e14;
const int mod = 1e9 + 7;

void solve() {
	LL x, y, z;
	cin >> x >> y >> z;
	LL a = z, t = max(y - a, x + a);
	LL b = (t + z - 1) / z * z;
	cout << a << ' ' << b << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;	
	while(t--) {
		solve();
	}
	return 0;
}
