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
	vector<int> a(n), b(m), c;
	map<int, int> vis;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		c.push_back(a[i]);
		vis[a[i]] = 1;
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
		c.push_back(b[i]);
	}
	sort(c.begin(), c.end());
	for(int i = 0; i + 1 < n + m; i++) {
		if(vis.count(c[i]) && vis.count(c[i + 1])) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}