#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <set>
#include <cstdio>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const double PI = acos(-1);
const double eps = 1e-8;
const int N = 55;

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
}O;
pair<Point, int> p[N];
typedef Point Vector;

// 点积 A·B = |A||B|cos(C)
// 意义：向量 a 的长度与向量 b 在 a 上的投影的长度的乘积
double dot(Point a, Point b) {
	return a.x * b.x + a.y * b.y;	
}

//计算向量的模
double get_length(Point a) {
	return sqrt(dot(a, a));	
}

// 叉积 AxB = |A||B|sin(C)
// 意义：向量 a 和向量 b 构成的平行四边形的有向面积
double cross(Point a, Point b) {
	return a.x * b.y - b.x * a.y;	
}

bool comp(const pair<Point, int> &x, const pair<Point, int> &y) {
	Point a = x.x, b = y.x;
	double c = cross(a - O, b - O);
	if(sign(c) > 0) return true;
	if(sign(c) < 0) return false;
	return cmp(get_length(a - O), get_length(b - O)) < 0;	// 共线
}

void solve() {
	int n;
	cin >> n;
	double miny = INF;
	for(int i = 1, x; i <= n; i++) {
		cin >> x >> p[i].x.x >> p[i].x.y;
		p[i].y = i;
		miny = min(miny, p[i].x.y);
	}

	vector<int> ans;
	O = Point(0, miny);
	for(int i = 1; i <= n; i++) {
		sort(p + i, p + n + 1, comp);
		ans.push_back(p[i].y);
		O = p[i].x;
	}
	cout << sz(ans);
	for(int i = 0; i < sz(ans); i++) {
		cout << ' ' << ans[i];
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}