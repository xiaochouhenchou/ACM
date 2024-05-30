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
	vector<PII> range;
	for(int i = 0, l, r; i < n; i++) {
		cin >> l >> r;
		range.emplace_back(l, r);
	}
	sort(range.begin(), range.end());
	ll ans = 0;
	for(int i = 0; i + 1 < n; i++) {
		auto [l, r] = range[i];

		int low = i + 1, high = n - 1;
		while(low < high) {
			int mid = (low + high) / 2;
			if(range[mid].x >= l) high = mid;
			else low = mid + 1;
		}
		if(range[high].x >= l) {
			int L = high;
			low = i + 1, high = n - 1;
			while(low < high) {
				int mid = (low + high + 1) / 2;
				if(range[mid].x <= r) low = mid;
				else high = mid - 1;
			}
			if(range[high].x <= r) {
				// cout << l << ' ' << r << ' ' << L << ' ' << high << '\n';
				ans += high - L + 1;
			}
		}
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