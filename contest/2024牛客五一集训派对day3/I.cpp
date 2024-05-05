#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

// 题解：https://blog.csdn.net/qq_45458915/article/details/107924613
void solve() {
	int n;
	cin >> n;
	vector<PII> p;
	for(int j = 2; j <= n; j++) {
		for(int i = 1; i < min(j, n - j + 1); i++) {
			p.emplace_back(i, j);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(i >= n - j + 1) {
				p.emplace_back(i, j);
			}
		}
	}
//	cout << get_res() << '\n';
	for(auto [x, y] : p) {
		cout << x << ' ' << y << '\n';
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
