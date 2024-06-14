#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<int> X(n), Y(n), Z(n);
	map<int, vector<int>> mp1, mp2;
	for(int i = 0; i < n; i++) {
		cin >> X[i] >> Y[i] >> Z[i];
		mp1[Z[i]].push_back(i);
	}
	vector<int> lastz, lasty;
	vector<PII> ans;
	for(auto &[z, v1] : mp1) {
		mp2.clear();
		for(auto &i : v1) {
			mp2[Y[i]].push_back(i);
		}
		lasty.clear();
		for(auto &[y, v2] : mp2) {
			sort(v2.begin(), v2.end(), [&](const int &x, const int &y) {
				return X[x] < X[y];
			});
			for(int i = 0; i + 1 < sz(v2); i += 2) {
				ans.emplace_back(v2[i], v2[i + 1]);
			}
			if(sz(v2) & 1) {
				lasty.push_back(v2.back());
			}
		}
		sort(lasty.begin(), lasty.end(), [&](const int &x, const int &y) {
			return Y[x] < Y[y];
		});
		for(int i = 0; i + 1 < sz(lasty); i += 2) {
			ans.emplace_back(lasty[i], lasty[i + 1]);
		}
		if(sz(lasty) & 1) {
			lastz.push_back(lasty.back());
		}
	}
	sort(lastz.begin(), lastz.end(), [&](const int &x, const int &y) {
		return Z[x] < Z[y];
	});
	for(int i = 0; i + 1 < sz(lastz); i += 2) {
		ans.emplace_back(lastz[i], lastz[i + 1]);
	}
	for(auto &[x, y] : ans) {
		cout << x + 1 << ' ' << y + 1 << '\n';
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