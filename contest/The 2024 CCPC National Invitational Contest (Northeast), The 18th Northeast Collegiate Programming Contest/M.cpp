#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

typedef pair<ll, ll> Point;
typedef Point Vector;

Point operator - (Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}

ll dot(Point a, Point b) {
	return a.x * b.x + a.y * b.y;	
}

ll cross(Point a, Point b) {
	return a.x * b.y - b.x * a.y;
}

ll get_dis(Point a, Point b) {
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	return dx * dx + dy * dy;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> x(n + 1), y(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			ll up = 0, cnt = 0;
			Point D(x[i], y[i]), C(x[j], y[j]);
			map<ll, ll> mp;
			for(int k = 1; k <= n; k++) {
				if(k == i || k == j) continue;
				Point X(x[k], y[k]);
				if(cross(C - D, X - D) == 0) {
					continue;
				}
				if(cross(C - D, X - D) > 0) {
					if(get_dis(X, D) == get_dis(X, C)) {
						up += 1;
					}
				} else {
					if(dot(X - D, C - D) == 0) {
						mp[get_dis(X, D)] += 1;
					}
					if(dot(X - C, D - C) == 0) {
						mp[get_dis(X, C)] += 1;
					}
				}
			}
			for(auto [d, c] : mp) {
				if(c >= 2) {
					cnt += 1;
				}
			}
			ans += up * cnt;
		}
	}
	cout << ans << '\n';
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}