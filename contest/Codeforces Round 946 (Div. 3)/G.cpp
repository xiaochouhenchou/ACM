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
	int m, x;
	cin >> m >> x;
	int sum = 0, ans = 0;
	priority_queue<int> q;
	for(int i = 1, c; i <= m; i++) {
		cin >> c;
		sum += c;
		q.push(c);
		while(sz(q) && sum > (i - 1) * x) {
			sum -= q.top();
			q.pop();
		}
		ans = max(ans, sz(q));
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}