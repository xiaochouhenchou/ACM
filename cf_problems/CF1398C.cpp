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
	string str;
	cin >> n >> str;
	vector<int> s(n + 1);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + (str[i - 1] - '0');
	}
	ll ans = 0;
	map<int, int> mp;
	mp[0] += 1;
	for(int i = 1; i <= n; i++) {
		if(mp.count(s[i] - i)) {
			ans += mp[s[i] - i];
		}
		mp[s[i] - i] += 1;
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