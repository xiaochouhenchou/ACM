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
	思路: 考虑答案的下界为 x_max - x_min + y_max - y_min。 根据答案构造
		  一组方案即可。
*/
void solve() {
	int x, y;
	vector<PII> p;
	for(int i = 0; i < 3; i++) {
		cin >> x >> y;
		p.emplace_back(x, y);
	}
	sort(p.begin(), p.end());
	auto [x1, y1] = p[0];
	auto [x2, y2] = p[1];
	auto [x3, y3] = p[2];
	vector<int> v{y1, y2, y3};
	sort(v.begin(), v.end());
	cout << 4 << '\n';
	cout << x1 << ' ' << v[1] << ' ' << x3 << ' ' << v[1] << '\n';
	cout << x1 << ' ' << y1 << ' ' << x1 << ' ' << v[1] << '\n';
	cout << x2 << ' ' << y2 << ' ' << x2 << ' ' << v[1] << '\n';
	cout << x3 << ' ' << y3 << ' ' << x3 << ' ' << v[1] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}