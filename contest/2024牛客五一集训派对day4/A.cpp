#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 5010;

bool f[N][N];

void init(int n) {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			if(!f[i][j]) {
				for(int k = 1; k + i <= n; k++) {
					for(int s = 0; s * k + j <= n; s++) {
						f[i + k][s * k + j] = 1;
					}
				}
				for(int k = 1; k + j <= n; k++) {
					for(int s = 0; s * k + i <= n; s++) {
						f[s * k + i][j + k] = 1;
					}
				}
			}
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	cout << (f[n][m] ? "Alice\n" : "Bob\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init(5000);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;	
}
