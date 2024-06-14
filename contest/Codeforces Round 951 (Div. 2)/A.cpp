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
	vector<int> a(n);
	for(auto &x : a) {
		cin >> x;
	}
	int minv = inf;
	for(int i = 0; i + 1 < n; i++) {
		minv = min(minv, max(a[i], a[i + 1]));
	}
	cout << minv - 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}