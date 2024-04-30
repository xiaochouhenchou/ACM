#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const double eps = 1e-8;
const int mod = 1e9 + 7;

void solve() {
	vector<vector<int>> b(7, vector<int>(6));
	for(auto &v : b) {
		for(auto &x : v) {
			cin >> x;
		}
	}

	auto ne = [&](int i) {
		return (i + 1) % 6;
	};
	auto pre = [&](int i) {
		return (i - 1 + 6) % 6;
	};	

	vector<int> p(7);
	iota(p.begin(), p.end(), 0);
	auto check = [&] {
		vector<vector<int>> a;
		for(int x : p) {
			a.push_back(b[x]);
		}
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j < 6; j++) {
				if(a[0][i] != a[1][j]) continue;
				int x1 = a[0][ne(i)];
				int x2 = a[0][ne(ne(i))];
				int y1 = a[1][pre(j)];
				int y2 = a[1][pre(pre(j))];
				for(int k = 0; k < 6; k++) {
					if(a[2][k] != x2) continue;
					int z1 = a[2][ne(k)];
					int z2 = a[2][ne(ne(k))];

					for(int l = 0; l < 6; l++) {
						if(a[3][l] != a[2][ne(k)] || 
							a[3][ne(l)] != x1 || 
							a[3][ne(ne(l))] != y1) continue;
						int z3 = a[3][ne(ne(ne(l)))];
						int z4 = a[3][ne(ne(ne(ne(l))))];
						for(int m = 0; m < 6; m++) {
							if(a[4][m] != z3 || a[4][ne(m)] != y2) 
								continue;
							for(int n = 0; n < 6; n++) {
								if(a[5][n] != z2 ||
									a[5][ne(n)] != a[3][pre(l)])
									continue;

								int z5 = a[5][ne(ne(n))];
								for(int o = 0; o < 6; o++) {
									if(a[6][o] != z5 ||
										a[6][ne(o)] != z4 || 
										a[6][ne(ne(o))] != a[4][pre(m)]) 
										continue;
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;
	};
	do {
		if(check()) {
			cout << "YES\n";
			return;
		}
	} while(next_permutation(p.begin(), p.end()));
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;	
	while(t--) {
		solve();
	}
	return 0;
}
