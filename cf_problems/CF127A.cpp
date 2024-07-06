#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

double get_dis(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	double dis = 0;
	for(int i = 1; i < n; i++) {
		dis += get_dis(x[i - 1], y[i - 1], x[i], y[i]);
	}
	dis = dis * k / 50.0;
	cout << fixed << setprecision(8) << dis << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}