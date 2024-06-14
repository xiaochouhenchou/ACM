#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <numeric>
#include <cmath>
#include <iomanip>
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
};
typedef Point Vector;

// 叉积 AxB = |A||B|sin(C)
// 意义：向量 a 和向量 b 构成的平行四边形的有向面积
double cross(Point a, Point b) {
	return a.x * b.y - b.x * a.y;	
}

// 求 p + tv 和 q + tw 的交点
// cross(v, w) == 0 两直线平行或重合
// 否则
Point get_line_intersection(Point p, Vector v, Point q, Vector w) {
    Vector u = p - q;
    double t = cross(w, u) / cross(v, w);
    return p + v * t;
}

void solve() {
	int n;
	cin >> n;
	cout << "INTERSECTING LINES OUTPUT\n";
	while(n--) {
		Point a, b, c, d;
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
		Vector v = b - a, w = d - c;
		// a + tv  c + tw
		if(sign(cross(v, w)) == 0) {
			if(sign(cross(v, c - a)) == 0) {
				cout << "LINE\n";
			} else {
				cout << "NONE\n";
			}
		} else {
			cout << "POINT ";
			Point p = get_line_intersection(a, v, c, w);
			cout << fixed << setprecision(2) << p.x << ' ' << p.y << '\n';
		}
	}
	cout << "END OF OUTPUT\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	while(t--) solve();
	return 0;
}