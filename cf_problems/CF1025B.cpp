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
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	set<int> st;
	for(int i = 2; i <= a[1] / i; i++) {
		if(a[1] % i == 0) {
			st.insert(i);
			while(a[1] % i == 0) a[1] /= i;
		}
	}
	if(a[1] > 1) st.insert(a[1]);
	for(int i = 2; i <= b[1] / i; i++) {
		if(b[1] % i == 0) {
			st.insert(i);
			while(b[1] % i == 0) b[1] /= i;
		}
	}
	if(b[1] > 1) st.insert(b[1]);
	for(int x : st) {
		int ok = 1;
		for(int i = 2; i <= n; i++) {
			if(a[i] % x && b[i] % x) {
				ok = 0;
				break;
			}
		}
		if(ok) {
			cout << x << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}