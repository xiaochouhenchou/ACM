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

	string t = s;
	sort(t.begin(), t.end());
	string rt = t;
	reverse(rt.begin(), rt.end());
	if(t == rt) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	if(t == s) {
		cout << rt << '\n';
	} else {
		cout << t << '\n';
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