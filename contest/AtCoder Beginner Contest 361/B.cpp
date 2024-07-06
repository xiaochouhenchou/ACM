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
	如果是一维的情况，判断两条直线有没有公共部分就行（不能是端点）。推广到三维的情况就行
*/

void solve() {
	int a, b, c, d, e, f;
	int g, h, i, j, k, l;
	cin >> a >> b >> c >> d >> e >> f;
	cin >> g >> h >> i >> j >> k >> l;
	auto check = [&](int l, int r, int L, int R) {
		if(L < l && l < R) return true;
		if(L < r && r < R) return true;
		if(L <= l && r <= R) return true;
		if(l <= L && R <= r) return true;
		return false;
	};
	cout << (check(a, d, g, j) && check(b, e, h, k) && check(c, f, i, l)
			? "Yes\n" : "No\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}