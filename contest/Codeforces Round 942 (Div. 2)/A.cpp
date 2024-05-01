#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int &x : a) {
		cin >> x;
	}
	for(int &x : b) {
		cin >> x;
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > b[i]) {
			a.pop_back();
			a.push_back(b[i]);
			sort(a.begin(), a.end());
			ans += 1;
		}
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
