#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

/*
	思路: 
		a + b = (a & b) + (a | b)。 
		a12 = a[1] + a[2] = (a[1] & a[2]) + (a[1] | a[2])
		a23 = a[2] + a[3] = (a[2] & a[3]) + (a[2] | a[3])
		a13 = a[1] + a[3] = (a[1] & a[3]) + (a[1] | a[3])
		a[2] = (a12 + a23 - a13) / 2
		a[1] = a12 - a[2]
		a[3] = a23 - a[2]
		至此用了六次询问确定 a[1..3]，接着每两次询问确定 a[4..n] 即可，总次数 2n。 
*/
void solve() {
	int n, k;
	cin >> n >> k;
	auto ask1 = [&](int i, int j) {
		cout << "and " << i << ' ' << j << endl;
		int res;
		cin >> res;
		return res;
	};
	auto ask2 = [&](int i, int j) {
		cout << "or " << i << ' ' << j << endl;
		int res;
		cin >> res;
		return res;
	};
	int a12 = ask1(1, 2) + ask2(1, 2);
	int a13 = ask1(1, 3) + ask2(1, 3);
	int a23 = ask1(2, 3) + ask2(2, 3);
	vector<int> a(n + 1);
	a[2] = (a12 + a23 - a13) / 2;
	a[1] = a12 - a[2];
	a[3] = a23 - a[2];
	for(int i = 4; i <= n; i++) {
		int res = ask1(1, i) + ask2(1, i);
		a[i] = res - a[1];
	}
	sort(a.begin() + 1, a.end());
	cout << "finish " << a[k] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}