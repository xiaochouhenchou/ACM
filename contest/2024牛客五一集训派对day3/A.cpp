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
	int p;
	cin >> p;
	int n = p - 1;
	vector<int> vis(n + 1), ans;
	int cur = 1;
	while(sz(ans) < n) {
		vis[cur] = 1;
		ans.push_back(cur);
		int v1 = cur * 2 % p;
		int v2 = cur * 3 % p;
		if(v1 && !vis[v1]) {
			cur = v1;
		} else if(v2 && !vis[v2]) {
			cur = v2;
		} else {
			break;
		}
	}
	if(sz(ans) < n) cout << -1 << '\n';
	else {
		for(int i = 0; i < n; i++) {
			cout << ans[i] << " \n"[i == n - 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;	
}
