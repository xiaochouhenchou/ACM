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
	int n = sz(s), cnt = 0;
	for(char c : s) {
		cnt += c == '(';
	}

	int l = -1, r = -1;
	for(int i = 0; i < n; i++) {
		if(s[i] != '?') continue;
		
		if(cnt < n / 2) {
			cnt += 1;
			s[i] = '(';
			l = i;
		} else {
			s[i] = ')';
			if(r == -1) r = i;
		}
	}
	
	if(l == -1 || r == -1) {
		cout << "YES\n";
		return;
	}

	swap(s[l], s[r]);

	int ok = 1, v = 0;
	for(char c : s) {
		v += (c == '(' ? 1 : -1);
		if(v < 0) {
			ok = 0;
			break;
		}
	}
	ok &= v == 0;

	cout << (ok ? "NO\n" : "YES\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}