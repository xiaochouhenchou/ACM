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
	cin >> n >> m;
	vector<string> s(n);
	vector<int> x, y;
	for(auto &str : s) {
		cin >> str;
	}	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(s[i][j] == '#') {
				x.push_back(i);
			}
		}
	}
	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			if(s[i][j] == '#') {
				y.push_back(j);
			}
		}
	}
	cout << x[(sz(x) - 1) / 2] + 1 << ' ' 
		<< y[(sz(y) - 1) / 2] + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}