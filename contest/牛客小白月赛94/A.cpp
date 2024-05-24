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
	vector<vector<int>> a(3, vector<int>(3));
	for(auto &v : a) {
		for(auto &x : v) {
			cin >> x;
		}
	}
	string s;
	cin >> s;
	for(char c : s) {
		int v = c - '0' - 1;
		cout << a[v / 3][v % 3];
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}