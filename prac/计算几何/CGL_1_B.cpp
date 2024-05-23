#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const double eps = 1e-10;

// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
int cmp(double x, double y) {
	if(fabs(x - y) < eps) return 0;
	if(x < y) return -1;
	return 1;
}	
int sign(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	return 1;
}
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

// 点积 A·B = |A||B|cos(C)
// 意义：向量 a 的长度与向量 b 在 a 上的投影的长度的乘积
double dot(Point a, Point b) {
	return a.x * b.x + a.y * b.y;	
}

// 叉积 AxB = |A||B|sin(C)
// 意义：向量 a 和向量 b 构成的平行四边形的有向面积
double cross(Point a, Point b) {
	return a.x * b.y - b.x * a.y;	
}

//计算向量的模
double get_length(Point a) {
	return sqrt(dot(a, a));	
}

// 点 p 在直线 ab 上的投影
Point get_line_projection(Point p, Point a, Point b) {
	Vector v = b - a;
	return a + v * (dot(v, p - a) / dot(v, v));	
}

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	Point A(a, b), B(c, d);
	int q;
	cin >> q;
	while(q--) {
		int x, y;
		cin >> x >> y;
		Point p(x, y);
		auto mid = get_line_projection(p, A, B);
		auto ans = mid * 2 - p;
		cout << fixed << setprecision(10) << ans.x 
			<< ' ' << ans.y << '\n';
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