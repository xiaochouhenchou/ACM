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
	int n, m;
	cin >> n >> m;
	multiset<int> st;
	for(int i = 0, a; i < n; i++) {
		cin >> a;
		st.emplace(a);
	}
	ll ans = 0;
	for(int i = 0, b; i < m; i++) {
		cin >> b;
		auto it = st.lower_bound(b);
		if(it == st.end()) {
			ans = -1;
			break;
		}
		ans += *it;
		st.erase(it);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}