#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int N = 300 * 60000 + 3;
const ull P = 1e9 + 7;

int n, m, q, k;

void solve() {
	cin >> n >> q >> m >> k;
	vector<string> s(n + 1);
	vector<ull> p(m + 1);
	p[0] = 1;
	for(int i = 1; i <= m; i++) {
		p[i] = p[i - 1] * P;
	}
	vector<vector<ull>> a(n + 2, vector<ull>(m + 1));
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
		for(int j = 1; j <= m; j++) {
			a[i][j] = a[i][j - 1] * P + s[i][j] - 'a';
		}
	}
	auto get = [&](vector<ull> &h, int l, int r) {
		return h[r] - h[l - 1] * p[r - l + 1];
	};

	while(q--) {
		string t;
		cin >> t;
		t = " " + t;
		for(int i = 1; i <= m; i++) {
			a[n + 1][i] = a[n + 1][i - 1] * P + t[i] - 'a';
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			int cnt = 0;
			for(int l = 1; l <= m && cnt <= k; ) {
				if(s[i][l] != t[l]) {
					cnt += 1;
					l += 1;
					continue;
				}

				int low = l, high = m;
				while(low < high) {
					int mid = (low + high + 1) / 2;
					if(get(a[i], l, mid) == get(a[n + 1], l, mid)) {
						low = mid;
					} else {
						high = mid - 1;
					}
				}
				l = high + 1;
			}
			ans += (cnt <= k);
		}
		cout << ans << '\n';
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