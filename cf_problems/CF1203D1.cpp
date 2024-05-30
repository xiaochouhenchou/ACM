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
	string s, t;
	cin >> s >> t;
	int ans = 0;
	auto check = [&](int l, int r) {
		for(int i = 0, j = 0; i < sz(s); i++) {
			if(l <= i && i <= r) continue;
			if(s[i] == t[j]) {
				j += 1;
			}
			if(j == sz(t)) return true;
		}
		return false;
	};
	for(int i = 0; i < sz(s); i++) {
		for(int j = i; j < sz(s); j++) {
			if(check(i, j)) {
				ans = max(ans, j - i + 1);
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