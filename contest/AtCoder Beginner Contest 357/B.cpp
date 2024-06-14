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
	int u = 0;
	for(char c : s) {
		if(c >= 'A' && c <= 'Z') {
			u += 1;
		}
	}
	if(u > sz(s) - u) {
		for(char &c : s) {
			if(c >= 'a' && c <= 'z') {
				c = c - 'a' + 'A';
			}
		}
	} else {
		for(char &c : s) {
			if(c >= 'A' && c <= 'Z') {
				c = c - 'A' + 'a';
			}
		}
	}
	cout << s << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}