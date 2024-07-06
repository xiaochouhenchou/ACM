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
	string s, c;
	cin >> n >> m >> s;
	vector<int> cnt(n), ch(26);
	for(int i = 0, idx; i < m; i++) {
		cin >> idx;
		cnt[idx - 1] += 1;
	}
	cin >> c;
	for(char cc : c) {
		ch[cc - 'a'] += 1;
	}
	for(int i = 0, l = 0, r = 25; i < n; i++) {
		if(!cnt[i]) continue;
		while(l < 26 && !ch[l]) l += 1;
		s[i] = l + 'a';
		ch[l] -= 1;
		cnt[i] -= 1;

		while(cnt[i]) {
			while(r >= 0 && !ch[r]) r -= 1;
			cnt[i] -= 1;
			ch[r] -= 1;
		}
	}
	cout << s << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}