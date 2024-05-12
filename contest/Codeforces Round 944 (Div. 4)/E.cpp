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
	ll n, k, q;
	cin >> n >> k >> q;
	vector<ll> a(k + 1), b(k + 1);
	for(int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= k; i++) {
		cin >> b[i];
	}
	for(int i = 1; i <= q; i++) {
		ll d;
		cin >> d;
		if(!d) {
			cout << 0 << " \n"[i == q];
			continue;
		}
		int j = lower_bound(a.begin(), a.end(), d) - a.begin();
		assert(j >= 1);
		ll res = b[j - 1] + (d - a[j - 1]) * (b[j] - b[j - 1]) / (a[j] - a[j - 1]);
		cout << res << " \n"[i == q];
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