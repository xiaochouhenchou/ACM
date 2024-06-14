#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <numeric>
#include <cmath>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const double eps = 1e-8;
/*
返回值：
	负数 --> -1
	零   --> 0
	正数 --> 1
*/
int sign(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	return 1;
}

/*
返回值：
	x == y --> 0
	x < y  --> -1
	x > y  --> 1
*/
int cmp(double x, double y) {
	if(fabs(x - y) < eps) return 0;
	if(x < y) return -1;
	return 1;
}

// 二维坐标类
struct Point {
	double x, y;
	Point() {}
	Point(double xx, double yy) : x(xx), y(yy) {}
	Point operator + (const Point &b) {
		return Point(x + b.x, y + b.y);
	}
	Point operator - (const Point &b) {
		return Point(x - b.x, y - b.y);
	}
	Point operator * (const double &t) {
		return Point(t * x, t * y);
	}
	bool operator == (const Point &b) {
		return !cmp(x, b.x) && !cmp(y, b.y);
	}
};
typedef Point Vector;

// 叉积 AxB = |A||B|sin(C)
// 意义：向量 a 和向量 b 构成的平行四边形的有向面积
double cross(Point a, Point b) {
	return a.x * b.y - b.x * a.y;	
}

void solve() {
	int n;
	cin >> n;
	vector<Point> l(n), r(n), all;
	for(int i = 0; i < n; i++) {
		cin >> l[i].x >> l[i].y >> r[i].x >> r[i].y;
		all.push_back(Point(l[i].x, l[i].y));
		all.push_back(Point(r[i].x, r[i].y));
	}
	for(int i = 0; i < n * 2; i++) {
		for(int j = 0; j < n * 2; j++) {
			if(all[i] == all[j]) continue;
			Point p = all[i];
			Vector v = (all[j] - all[i]);
			int ok = 1;
			for(int k = 0; k < n; k++) {
				if(sign(cross(v, l[k] - p)) * sign(cross(v, r[k] - p)) > 0) {
					ok = 0;
					break;
				}
			}
			if(ok) {
				cout << "Yes!\n";
				return;
			}
		}
	}
	cout << "No!\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}