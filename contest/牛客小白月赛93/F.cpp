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
	string s;
	cin >> s;
	int n = sz(s), m, res;
	vector<int> a(n + 1), suf(n + 1), cnt(26);
	for(m = 1; m <= n; m++) {
		if(n % m) continue;

		res = 0;
		for(int i = 0; i < m; i++) {
			fill(cnt.begin(), cnt.end(), 0);
			for(int j = i; j < n; j += m) {
				cnt[s[j] - 'a'] += 1;
			}
			a[i] = *max_element(cnt.begin(), cnt.end());
			res += a[i];
		}
		if(res >= (n + 1) / 2) {
			break;
		}
	}
	for(int i = m - 1; i >= 0; i--) {
		suf[i] = suf[i + 1] + a[i];
	}

	string ans = "";
	int pre = 0;
	for(int i = 0, c; i < m; i++) {
		fill(cnt.begin(), cnt.end(), 0);
		for(int j = i; j < n; j += m) {
			cnt[s[j] - 'a'] += 1;
		}
		for(c = 0; c < 26; c++) {
			if(pre + cnt[c] + suf[i + 1] >= (n + 1) / 2) {
				break;
			}
		}
		pre = pre + cnt[c];
		ans.push_back(c + 'a');
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