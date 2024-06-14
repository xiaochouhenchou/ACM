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
	int n, f, k;
	cin >> n >> f >> k;
	vector<PII> p;
	vector<int> vis(101), mp(101), a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		p.emplace_back(a[i], i);
		mp[a[i]] += 1;
	}
	sort(p.rbegin(), p.rend());
	for(int i = 0; i < k; i++) {
		vis[p[i].x] += 1;
	}
	if(vis[a[f]]) {
		if(vis[a[f]] >= mp[a[f]]) {
			cout << "YES\n";
		} else {
			cout << "MAYBE\n";
		}
	} else {
		cout << "NO\n";
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