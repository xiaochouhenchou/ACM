#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 998244353;

ll get(string &s) {
	ll res = 0;
	for(char c : s) {
		res = res * 10 + c - '0';
		res %= mod;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;
	for(int i = 0; i < n; i++) {
		if(a[i] > b[i]) {
			swap(a[i], b[i]);
		}
	}
	cout << get(a) * get(b) % mod << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}