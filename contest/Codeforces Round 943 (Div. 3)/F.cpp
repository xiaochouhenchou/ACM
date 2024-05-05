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
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), s(n + 1);
	map<int, vector<int>> mp;
	mp[s[0]].push_back(0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
		// cout << s[i] << " \n"[i == n];
		mp[s[i]].push_back(i);
	}	
	while(q--) {
		int l, r;
		cin >> l >> r;
		int ok = s[l - 1] == s[r];
		auto it = lower_bound(mp[s[r]].begin(), mp[s[r]].end(), l);
		if(it != mp[s[r]].end() && *it <= r - 1) {
			auto it2 = lower_bound(mp[s[l - 1]].begin(), mp[s[l - 1]].end(), r);
			if(it2 != mp[s[l - 1]].begin()) {
				it2--;
				if(*it2 > *it) {
					ok = 1;
				}
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
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
