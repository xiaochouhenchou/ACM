#include <iostream>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 5005;

int n, m, a, b, c, d;
int U[N], L[N], ans[N];

// 二维坐标类
struct Point {
	int x, y;
	Point() {}
	Point(int xx, int yy) : x(xx), y(yy) {}
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
		return x == b.x && y == b.y;
	}
	bool operator < (const Point &b) {
		if(x != b.x) return x < b.x;
		return y < b.y;
	}
}points[N];
typedef Point Vector;

// 叉积 AxB = |A||B|sin(C)
// 意义：向量 a 和向量 b 构成的平行四边形的有向面积
int cross(Point a, Point b) {
	return a.x * b.y - b.x * a.y;	
}

bool check(int i, int j) {
	Point A(L[i], d), B(U[i], b);
	return cross(B - A, points[j] - A) > 0;
}

void solve() {
	cin >> m >> a >> b >> c >> d;
	for(int i = 0; i < n; i++) {
		cin >> U[i] >> L[i];
	}
	fill(ans, ans + n + 1, 0);
	for(int i = 0; i < m; i++) {
		cin >> points[i].x >> points[i].y;
		int l = 0, r = n - 1;
		while(l < r) {
			int mid = (l + r) / 2;
			if(check(mid, i)) r = mid;
			else l = mid + 1;
		}
		if(!check(r, i)) {
			ans[r + 1] += 1;
		} else {
			ans[r] += 1;
		}
	}
	for(int i = 0; i <= n; i++) {
		cout << i << ": " << ans[i] << '\n';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	while(cin >> n, n) {
		solve();
	}
	return 0;
}