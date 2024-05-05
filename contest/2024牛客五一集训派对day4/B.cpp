#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	ll r, a, b, h;
	cin >> r >> a >> b >> h;
	if(r * 2 < b) {
		cout << "Drop\n";
		return;
	}
	double ad2 = 1.0 * a / 2.0;
	double bd2 = 1.0 * b / 2.0;
	double t = 1.0 * (a - b) / 2.0;
	double c2 = h * h + t * t;
	double N = c2 + bd2 * bd2 - ad2 * ad2 - h * h;
	double M = r * r - bd2 * bd2;
	double B = -4.0 * h * N;
	double A = 4.0 * (c2 - h * h);
	double C = -(N * N + 4.0 * M * c2);
	double delta = B * B - 4.0 * A * C;
	double x1 = (-B + sqrtl(delta)) / (2.0 * A);
	double x2 = (-B - sqrtl(delta)) / (2.0 * A);
	cout << "Stuck\n" << fixed << setprecision(8) << x1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;	
}
