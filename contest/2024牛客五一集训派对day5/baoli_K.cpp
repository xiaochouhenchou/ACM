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
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	// while(t--) solve();
	int n;
	cin >> n;
	vector<int> p(n);
	iota(p.begin(), p.end(), 1);
	do {
		vector<int> stk;
		for(int i = 0; i < n; i++) {
			cout << p[i] << " \n"[i == n - 1];
		}
		for(int i = 0; i < n; i++) {
			while(sz(stk) && p[stk.back()] > p[i]) stk.pop_back();
			stk.push_back(i);
			cout << sz(stk) << " \n"[i == n - 1];
		}
		cout << "-----------------------\n";
	} while(next_permutation(p.begin(), p.end()));
	return 0;
}