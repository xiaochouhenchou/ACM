#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

int n, k;
int a[][3] = {
	{0, 0, 0},
	{0, 0, 3},
	{0, 1, 2}
};
vector<int> v;

void dfs(int x, int y, int i) {
	if(i == 1) {
		v.push_back(a[x][y]);
		return;
	}
	int len = (1 << (i - 1));
	if(x <= len && y <= len) {	// 关于主对角线变化坐标
		v.push_back(0);
		dfs(y, x, i - 1);
	}
	if(x <= len && y > len) {	// 关于副对角线变化坐标
		v.push_back(3);
		dfs((1 << i) - y + 1, len - x + 1, i - 1);
	}
	if(x > len && y <= len) {	// 直接加减 len 变化坐标
		v.push_back(1);
		dfs(x - len, y, i - 1);
	}
	if(x > len && y > len) {	// 直接加减 len 变化坐标
		v.push_back(2);
		dfs(x - len, y - len, i - 1);
	}
}

typedef pair<vector<int>, int> PVI;
/*
	思路：可以发现路线一定是从左上角进来，依次经过左下角、右下角，从右上角出去。
		 那么分别给这四个角赋值 0,1,2,3 ，从原来的坐标 (x, y) 开始，递归
		 到 2 * 2 的正方形，那么每个坐标可以得到长度相同的 vector，可以看
		 成一个四进制的数，排序比较这些 vector 就可以将坐标排好序
*/
void solve() {
	cin >> n >> k;
	vector<int> x(n), y(n);
	vector<PVI> b(n);
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		v.clear();
		dfs(x[i], y[i], k);
		b[i] = {v, i};
	}
	sort(b.begin(), b.end(), [&](const PVI &u, const PVI &v) {
		if(u.x != v.x) return u.x < v.x;
		return u.y < v.y;
	});
	for(int i = 0; i < n; i++) {
		cout << x[b[i].y] << ' ' << y[b[i].y] << '\n';
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
