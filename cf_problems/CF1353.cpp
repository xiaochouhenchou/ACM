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
	priority_queue<PII, vector<PII>, greater<PII>> q;
	vector<int> a(n + 1);
	q.emplace(-n, 1);
	for(int i = 1; i <= n; i++) {
		assert(sz(q) >= 1);
		auto [len, l] = q.top();
		q.pop();

		len = -len;
		int r = l + len - 1;
		int mid = l + (len + 1) / 2 - 1;
		a[mid] = i;
		if(l <= mid - 1) {
			q.emplace(l - mid, l);
		}
		if(mid + 1 <= r) {
			q.emplace(mid - r, mid + 1);
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << a[i] << " \n"[i == n];
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