#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const double eps = 1e-8;
const int mod = 1e9 + 9;

void solve() {
	int n, k, s;
	cin >> n >> k >> s;
	vector<int> a(n);

	for(int i = 0, val = 1; i < k / 2 * 2; i++) {
		for(int j = i; j < n; j += k) {
			a[j] = val;
		}
		val = 3 - val;
	}
	if(k & 1) {
		if(n == k) {
			a[k - 1] = 1;
		} else {
			for(int j = k - 1; j < n; j += k) {
				a[j] = 3;
			}			
		}
	}
	
	int ok = 1;
	for(int i = 0; i + 1 < n; i++) {
		if(a[i] == a[i + 1]) {
			ok = 0;
			break;
		}
	}
	if(accumulate(a.begin(), a.end(), 0ll) > s) {
		ok = 0;
	}
	if(!ok) cout << "NO\n";
	else {
		cout << "YES\n";
		for(int i = 0; i < n; i++) {
			cout << a[i] << " \n"[i == n - 1];
		}	
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;	
	while(t--) {
		solve();
	}
	return 0;
}
