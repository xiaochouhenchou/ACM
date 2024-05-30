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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> cnt(26);
	for(char c : s) {
		cnt[c - 'a'] += 1;
	}
	string ans = "";
	int v = 0, last = 0, c = 0;
	for(int i = 0; i < 26 && v < k; i++) {
		int tmp = min(k - v, cnt[i]);
		v += tmp;
		cnt[i] -= tmp;
		if(tmp) last = i, c += 1;
	}	
	ans.push_back(last + 'a');
	for(int i = last; i < 26; i++) {
		while(cnt[i]--) {
			ans.push_back(i + 'a');
		}
	}
	if(c != 1) {
		cout << ans.front() << '\n';
		return;
	}

	int i = 1;
	c = 0;
	while(i < sz(ans) - 1 && ans.back() <= ans[i]) {
		if(c == k - 1) {
			c = 0;
			i += 1;
			continue;
		}
		ans.pop_back();
		c += 1;
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