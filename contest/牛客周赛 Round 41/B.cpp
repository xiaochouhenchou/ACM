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
	int n, k;
	cin >> n >> k;
	vector<int> p(n + 1), mp(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		mp[p[i]] = i;
	}

	if(k > n || k <= 1) {
		cout << -1 << '\n';
		return;
	}

	vector<int> q(n + 1);
	for(int i = 0; i < k; i++) {
		q[mp[i + 1]] = (i + 1) % k + 1;
	}
	for(int i = k; i < n; i++) {
		q[mp[i + 1]] = p[mp[i + 1]];
	}
	for(int i = 1; i <= n; i++) {
		cout << q[i] << " \n"[i == n];
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