#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 110;

void solve() {
	ll n, x;
	cin >> n >> x;
	ll cnt = 0;
	for(ll i = 1; i <= x / i; i++) {
		if(x % i == 0) {
			cnt += (i <= n);
			if(x / i != i) cnt += (x / i <= n);
		}
	}
	cout << (cnt % 2 ? "ON\n" : "OFF\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}