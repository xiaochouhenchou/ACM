#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < n; ) {
			if(s[j] != '0') {
				j += 1;
				continue;
			}
			int k = j + 1;
			while(k < n && s[k] == '0') k += 1;
			ans += max(k - j - m + 1, 0);
			j = k;
		}
	}
	cin >> s;
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
