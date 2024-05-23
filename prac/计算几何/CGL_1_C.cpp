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

// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
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

void solve() {
	int a, b, c, d, q;
	cin >> a >> b >> c >> d >> q;
	Point A(a, b), B(c, d);
	while(q--) {
		int x, y;
		cin >> x >> y;
		Point C(x, y);
		
		Vector a = B - A, b = C - A;
		if(sign(cross(a, b)) > 0) {
			cout << "COUNTER_CLOCKWISE\n";
		} else if(sign(cross(a, b)) < 0) {
			cout << "CLOCKWISE\n";
		} else {
			if(sign(dot(a, b)) < 0) {
				cout << "ONLINE_BACK\n";
			} else if(cmp(get_length(b), get_length(a)) > 0) {
				cout << "ONLINE_FRONT\n";
			} else {
				cout << "ON_SEGMENT\n";
			}
		}
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