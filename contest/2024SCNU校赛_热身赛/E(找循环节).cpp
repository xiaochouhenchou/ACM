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
	思路： 相邻两项确定后面的数，因此如果当前两项已经在前面出现过了，
		那么循环节就出现了。用 map 记录相邻两项的起始位置即可。
*/
void solve() {
	int a, b, n;
	cin >> b >> a >> n;
	a %= 7, b %= 7;

	int x = 1, y = 1;
	int st = -1, len = -1;	// 循环节起始位置、环的长度
	map<PII, int> mp;
	mp[{x, y}] = 2;
	vector<int> v{0, x, y};
	for(int i = 3; i <= 100; i++) {
		int z = (a * x % 7 + b * y % 7) % 7;
		v.push_back(z);
		x = y, y = z;
		if(mp.count({x, y})) {
			st = mp[{x, y}];
			len = i - mp[{x, y}];
			break;
		}
		mp[{x, y}] = i;
	}
	if(n < st) {
		cout << v[n] << '\n';
	} else {
		n -= st;
		cout << v[st + n % len] << '\n';
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