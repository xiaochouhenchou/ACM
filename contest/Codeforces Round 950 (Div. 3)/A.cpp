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
	int n, m;
	string s;
	cin >> n >> m >> s;
	vector<int> cnt(7);
	for(char c : s) {
		cnt[c - 'A'] += 1;
	}
	int ans = 0;
	for(int i = 0; i < 7; i++) {
		ans += max(m - cnt[i], 0);
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