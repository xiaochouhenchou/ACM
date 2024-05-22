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
	string b;
	cin >> n >> b;
	vector<int> cnt(26), to(26);
	for(char c : b) {
		cnt[c - 'a'] += 1;
	}
	string t = "";
	for(int i = 25; i >= 0; i--) {
		if(cnt[i]) t.push_back(i + 'a');
	}
	for(int i = 0; i < sz(t); i++) {
		to[t[i] - 'a'] = t[sz(t) - 1 - i] - 'a';
	}
	for(char &c : b) {
		c = to[c - 'a'] + 'a';
	}
	cout << b << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}