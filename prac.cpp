#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void work(int n, string s) {
	set<string> st;
	st.emplace(s);
	int ok = 0;
	cout << s << '\n';
	for(int i = 1; i <= n * 2; i++) {
		string t = s;
		for(int j = 0; j < n; j++) {
			if(s[j] == '1') {
				if(j - 1 >= 0 && s[j - 1] != '1') {
					t[j - 1] ^= 1;
				}
				if(j + 1 < n && s[j + 1] != '1') {
					t[j + 1] ^= 1;
				}
				t[j] ^= 1;
			}
		}
		if(st.find(t) != st.end()) {
			ok = 1;
		}
		st.emplace(t);
		s = t;
		cout << s << '\n';
	}
}

void solve() {
	// int n;
	// cin >> n;
	// for(int i = 1; i < (1 << n); i++) {
	// 	string s = string(n, '0');
	// 	for(int j = 0; j < n; j++) {
	// 		if(i >> j & 1) s[j] = '1';
	// 	}
	// 	work(n, s);
	// 	cout << "--------------\n";
	// }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}