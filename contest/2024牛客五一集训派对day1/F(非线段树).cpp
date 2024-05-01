#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 100010;

int n, r;
int row[N], col[N], X[N], Y[N];
map<PII, int> mp;

int get_row(int x) {
	return x >= 0 && x < N ? row[x] : 0;
}

int get_col(int y) {
	return y >= 0 && y < N ? col[y] : 0;
}

int get_point(int x, int y) {
	return mp.count({x, y}) ? mp[{x, y}] : 0;
}

void solve() {
	cin >> n >> r;
	for(int i = 1; i <= n; i++) {
		cin >> X[i] >> Y[i];
		mp[{X[i], Y[i]}] += 1;
		row[X[i]] += 1;
		col[Y[i]] += 1;
	}	

	vector<PII> rp, cp;
	for(int i = 0; i < N; i++) {
		int res = 0;
		for(int j = 0; j < 3; j++) {
			res += get_row(i + j * r);
		}
		rp.emplace_back(res, i);
	}
	for(int i = 0; i < N; i++) {
		int res = 0;
		for(int j = 0; j < 3; j++) {
			res += get_col(i + j * r);
		}
		cp.emplace_back(res, i);
	}	
	sort(rp.begin(), rp.end());
	sort(cp.begin(), cp.end());

	int ans = 0;
	for(int i = N - 6; i < N; i++) {
		for(int j = N - 6; j < N; j++) {
			int res = rp[i].x + cp[j].x;
			int x = rp[i].y, y = cp[j].y;
			for(int u = 0; u < 3; u++) {
				for(int v = 0; v < 3; v++) {
					res -= get_point(x + u * r, y + v * r);
				}
			}
			ans = max(ans, res);
		}
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;	
}
