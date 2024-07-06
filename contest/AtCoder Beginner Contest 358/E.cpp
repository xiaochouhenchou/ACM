#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1000;
const int mod = 998244353;

int n, c[27], com[N + 1][N + 1];
int f[27][N + 1];

void solve() {	
	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= i; j++) {
			if(!j) com[i][j] = 1;
			else com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % mod;
		}
	}
	auto C = [&](int a, int b) {
		if(a < b) return 0;
		return com[a][b];
	};
	
	cin >> n;
	for(int i = 1; i <= 26; i++) {
		cin >> c[i];
	}

	f[0][0] = 1;
	for(int i = 1; i <= 26; i++) {
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k <= min(c[i], j); k++) {
				f[i][j] = (f[i][j] + 1ll * f[i - 1][j - k] * C(j, k) % mod) % mod;
			}
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = (ans + f[26][i]) % mod;
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