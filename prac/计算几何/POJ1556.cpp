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

const int N = 110;

int n, m, mp[21][6], vis[N];
double dis[N], e[N][N];
vector<Point> points[21];

/*
	枚举任意两个墙上的点 a、b，如果 线段 ab 没有穿过任何墙（和墙没有交点或者交点是墙的端点），
	就从 a -> b 连一条长度为 |ab| 的边，最后跑最短路即可。
*/

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

// 点 p 是否在线段 ab 上
bool on_segment(Point p, Point a, Point b) {
    // 共线且 p 在 ab 之间
	return sign(cross(p - a, p - b)) == 0
			&& sign(dot(p - a, p - b)) <= 0;
}

// 求 p + tv 和 q + tw 的交点
// cross(v, w) == 0 两直线平行或重合
// 否则
Point get_line_intersection(Point p, Vector v, Point q, Vector w) {
    Vector u = p - q;
    double t = cross(w, u) / cross(v, w);
    return p + v * t;
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

// 线段 ab 有没有穿过墙 
bool check(Point a, Point b) {
	for(int i = 2; i <= n + 1; i++) {
		double x = points[i][0].x;
		vector<Point> p;
		if(segment_intersection(a, b, Point(x, 0), points[i][1])) {
			Point t = get_line_intersection(a, b - a, Point(x, 0), 
				points[i][1] - Point(x, 0));
			p.push_back(t);
		}
		if(segment_intersection(a, b, points[i][2], points[i][3])) {
			Point t = get_line_intersection(a, b - a, points[i][2], 
				points[i][3] - points[i][2]);	
			p.push_back(t);		
		}
		if(segment_intersection(a, b, points[i][4], Point(x, 10))) {
			Point t = get_line_intersection(a, b - a, points[i][4], 
				Point(x, 10) - points[i][4]);	
			p.push_back(t);
		}
		for(int j = 0; j < sz(p); j++) {
			int ok = 0;
			for(int k = 1; k < sz(points[i]); k++) {
				if(p[j] == points[i][k]) {
					ok = 1;
				}
			}
			if(!ok) return false;
		}
	}
	return true;
}

double dijkstra() {
	for(int i = 1; i <= m; i++) {
		dis[i] = INF;
		vis[i] = 0;
	}
	dis[1] = 0;
	for(int i = 0; i < m; i++) {
		int ver = -1;
		for(int j = 1; j <= m; j++) {
			if(!vis[j] && (ver == -1 || cmp(dis[ver], dis[j]) == 1)) {
				ver = j;
			}
		}

		vis[ver] = 1;
		for(int j = 1; j <= m; j++) {
			dis[j] = min(dis[j], dis[ver] + e[ver][j]);
		}
	}
	return dis[mp[n + 2][0]];
}

void solve() {
	while(cin >> n, ~n) {
		for(int i = 0; i < 21; i++) {
			points[i].clear();
		}
		m = 0;

		points[1].push_back(Point(0, 5));
		mp[1][0] = ++m;
		for(int i = 2; i <= n + 1; i++) {
			double x, y;
			cin >> x;
			points[i].push_back(Point(x, 5));
			for(int j = 0; j < 4; j++) {
				cin >> y;
				points[i].push_back(Point(x, y));
			}
			for(int j = 0; j < 5; j++) {
				mp[i][j] = ++m;
			}
		}
		points[n + 2].push_back(Point(10, 5));
		mp[n + 2][0] = ++m;

		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= m; j++) {
				e[i][j] = INF;
			}
		}
		
		for(int i = 1; i <= n + 2; i++) {
			for(int j = i + 1; j <= n + 2; j++) {
				for(int k = 0; k < sz(points[i]); k++) {
					for(int l = 0; l < sz(points[j]); l++) {
						if(check(points[i][k], points[j][l])) {
							e[mp[i][k]][mp[j][l]] = get_length(points[j][l] - 
								points[i][k]);
						}
					}
				}
			}
		}
		cout << fixed << setprecision(2) << dijkstra() << '\n';
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