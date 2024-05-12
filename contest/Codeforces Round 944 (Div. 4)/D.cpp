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
	vector<int> v;
	int cnt = 0;
	for(int i = 0; i < sz(s); ) {
		int j = i + 1;
		while(j < sz(s) && s[j] == s[i]) j += 1;
		v.push_back(s[i] - '0');
		i = j;
		cnt += 1;
	}
	for(int i = 0; i + 1 < sz(v); i++) {
		if(v[i] == 0 && v[i + 1] == 1) {
			cnt -= 1;
			break;
		}
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}