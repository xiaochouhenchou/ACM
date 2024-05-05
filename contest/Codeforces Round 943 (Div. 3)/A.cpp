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
	int x;
	cin >> x;
	int maxv = -inf, y = -1;
	for(int i = 1; i < x; i++) {
		int res = __gcd(x, i) + i;
		if(maxv < res) {
			maxv = res;
			y = i;
		}
	}
	cout << y << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;	
}
