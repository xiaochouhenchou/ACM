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
	vector<ll> x(n + 1), y(n + 1), z(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> z[i];
	}
	auto get_dis = [&](int i, int j) {
		ll dx = x[i] - x[j];
		ll dy = y[i] - y[j];
		ll dz = z[i] - z[j];
		return dx * dx + dy * dy + dz * dz;
	};
	vector<int> vis(n + 1);
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		ll minv = INF, idx = -1;
		for(int j = 1; j <= n; j++) {
			if(vis[j] || i == j) continue;
			if(minv > get_dis(i, j)) {
				minv = get_dis(i, j);
				idx = j;
			}
		}
		cout << i << ' ' << idx << '\n';
		vis[i] = vis[idx] = 1;
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