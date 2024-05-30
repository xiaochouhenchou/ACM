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
	int n, m, q;
	cin >> n >> m;
	vector<int> a(n + 1);
	vector<int> l(m + 1), r(m + 1);
	for(int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i];
	}
	cin >> q;
	vector<int> x(q + 1);
	for(int i = 1; i <= q; i++) {
		cin >> x[i];
	}
	auto check = [&](int mid) {
		fill(a.begin(), a.end(), 0);
		for(int i = 1; i <= mid; i++) {
			a[x[i]] = 1;
		}
		for(int i = 1; i <= n; i++) {
			a[i] += a[i - 1];
		}
		for(int i = 1; i <= m; i++) {
			int val = a[r[i]] - a[l[i] - 1];
			int len = r[i] - l[i] + 1;
			if(val > len - val) {
				return true;
			}
		}
		return false;
	};
	int low = 1, high = q;
	while(low < high) {
		int mid = (low + high) / 2;
		if(check(mid)) high = mid;
		else low = mid + 1;
	}
	if(!check(high)) high = -1;
	cout << high << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}