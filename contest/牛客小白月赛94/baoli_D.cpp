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
	cin >> n;
	vector<int> p(n);
	iota(p.begin(), p.end(), 1);
	do {
		int g = 0;
		for(int x : p) {
			g = __gcd(g, x);
			cout << g << ' ';
		}
		cout << '\n';
	} while(next_permutation(p.begin(), p.end()));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}