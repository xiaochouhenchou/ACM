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
	cout << n << ":";
	vector<PII> v;
	for(int i = 2; i <= n / i; i++) {
		if(n % i == 0) {
			int cnt = 0;
			while(n % i == 0) n /= i, cnt += 1;
			v.emplace_back(i, cnt);
		}
	}
	if(n > 1) v.emplace_back(n, 1);
	sort(v.begin(), v.end());
	for(auto [p, c] : v) {
		while(c--) {
			cout << " " << p;
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}