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
const double PI = acos(-1);

// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_2_B
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

// 点 p 是否在线段 ab 上
bool on_segment(Point p, Point a, Point b) {
    // 共线且 p 在 ab 之间
	return sign(cross(p - a, p - b)) == 0
			&& sign(dot(p - a, p - b)) <= 0;
}

// 判断两条线段 a1a2、b1b2 是否相交（跨立实验）
bool segment_intersection(Point a1, Point a2, Point b1, Point b2)
{
	// 特判四点共线
	Vector v = a2 - a1;
	Vector w = b2 - b1;
	if(sign(cross(v, w)) == 0) {
		return on_segment(b1, a1, a2) || on_segment(b2, a1, a2) 
			|| on_segment(a1, b1, b2) || on_segment(a2, b1, b2);
	}

	double c1 = cross(a2 - a1, b1 - a1); 
	double c2 = cross(a2 - a1, b2 - a1);
	double c3 = cross(b2 - b1, a1 - b1);
	double c4 = cross(b2 - b1, a2 - b1);
	return sign(c1) * sign(c2) <= 0 &&
			sign(c3) * sign(c4) <= 0;
}

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	Point A(a, b), B(c, d);
	cin >> a >> b >> c >> d;
	Point C(a, b), D(c, d);
	cout << segment_intersection(A, B, C, D) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}