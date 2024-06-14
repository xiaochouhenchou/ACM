#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const long double PI = acos(-1);
const long double eps = 1e-20;

/*
返回值：
	负数 --> -1
	零   --> 0
	正数 --> 1
*/
int sign(long double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	return 1;
}

// 二维坐标类
struct Point {
	long double x, y;
	Point() {}
	Point(long double xx, long double yy) : x(xx), y(yy) {}
	Point operator + (const Point &b) {
		return Point(x + b.x, y + b.y);
	}
	Point operator - (const Point &b) {
		return Point(x - b.x, y - b.y);
	}
	Point operator * (const long double &t) {
		return Point(t * x, t * y);
	}
}O;

long double theta(Point a) {
	long double res = atan2(a.y, a.x);
	if(sign(res) < 0) {
		res += PI * 2;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<Point, int>> p(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> p[i].x.x >> p[i].x.y;
		p[i].y = i;
	}
	sort(p.begin() + 1, p.end(), [&](const pair<Point, int> &x, 
		const pair<Point, int> &y) {
		Point a = x.x, b = y.x;
		return theta(a) < theta(b);
	});
	long double minv = theta(p[1].x) - theta(p[n].x) + PI * 2;
	int l = p[n].y, r = p[1].y;
	for(int i = 1; i + 1 <= n; i++) {
		if(minv > theta(p[i + 1].x) - theta(p[i].x)) {
			minv = theta(p[i + 1].x) - theta(p[i].x);
			l = p[i].y, r = p[i + 1].y;
		}
	}
	cout << l << ' ' << r << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}