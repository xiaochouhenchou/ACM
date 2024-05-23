#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

set<int> v[21];

void init(int n) {
	for(int i = 0; i < (1 << n); i++) {
		v[__builtin_popcount(i)].insert(i);
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	string A;
	cin >> A;
	int a = count(A.begin(), A.end(), '1');
	int mod = 1 << k;
	int B = inf;
	for(int b = 0; b <= k; b++) {
		if(v[b].count((a + b) % mod)) {
			B = min(B, (a + b) % mod);
		}
	}
	auto get = [&] {
		string s = "";
		while(B) {
			s.push_back(B % 2 + '0');
			B /= 2;
		}
		while(sz(s) < k) s.push_back('0');
		reverse(s.begin(), s.end());
		return s;
	};
	// cout << ": " << B << '\n';
	if(B == inf) cout << "None\n";
	else {
		cout << get() << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init(20);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}