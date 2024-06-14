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
	int n, k, l;
	cin >> n >> k >> l;
	vector<int> a(n * k);
	for(int i = 0; i < n * k; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int r = 0;
	for(int i = 1; i < n * k; i++) {
		if(a[i] - a[0] <= l) {
			r = i;
		} else {
			break;
		}
	}
	if(r + 1 < n) {
		cout << 0 << '\n';
		return;
	}

	ll sum = 0, cnt = n * k - 1 - r;
	for(int i = r; i >= 0; i--) {
		if(cnt < k - 1) {
			cnt += 1;
			continue;
		}
		sum += a[i];
		cnt -= k - 1;
	}
	cout << sum << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}