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
	int n, x;
	cin >> n >> x;
	map<int, int> mp;
	for(int i = 1, a; i <= n; i++) {
		cin >> a;
		if(i != x) {
			mp[a] += 1;
		}
	}
	cout << (mp.rbegin()->y) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}