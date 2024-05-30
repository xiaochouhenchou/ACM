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
	vector<int> a(n), b(n);
	for(auto &x : a) {
		cin >> x;
	}
	int cur = 0, top = 1e6;
	vector<int> can;
	for(int i = 0; i < n; i++) {
		if(cur > a[i]) {
			cout << -1 << '\n';
			return;
		}

		if(cur == a[i]) {
			b[i] = top;
			can.push_back(i);
		} else {
			if(sz(can) + 1 < (a[i] - cur)) {
				cout << -1 << '\n';
				return;
			}
			b[i] = cur;
			cur += 1;
			while(cur != a[i]) {
				b[can.back()] = cur;
				can.pop_back();
				cur += 1;
			}
		}
	}
	map<int, int> mp;
	int mex = 0;
	for(int i = 0; i < n; i++) {
		mp[b[i]] += 1;
		while(mp.count(mex)) mex += 1;
		if(mex != a[i]) {
			cout << -1 << '\n';
			return;
		}
	}
	for(int i = 0; i < n; i++) {
		cout << b[i] << " \n"[i == n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}