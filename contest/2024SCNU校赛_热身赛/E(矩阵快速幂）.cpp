#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 2, mod = 7;

void mul(int c[][N], int a[][N], int b[][N]) {
	static int res[N][N];
	memset(res, 0, sizeof res);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				res[i][j] += a[i][k] * b[k][j] % mod;
				res[i][j] %= mod;
			}
		}
	}
	memcpy(c, res, sizeof res);
}

/*
	f[n] = b * f[n - 1] + a * f[n - 2]
	令 F[n] = {f[n], f[n - 1]}

	F[n] = {f[n], f[n - 1]} = {f[n - 1], f[n - 2]} * {b, 1}
													 {a, 0}
	记后面的矩阵为 A，那么 F[n] = F[2] * A^(n - 2)
	用矩阵快速幂计算 A^(n - 2) 即可
*/
void solve() {
	int a, b, n;
	cin >> b >> a >> n;
	if(n <= 2) {
		cout << 1 << '\n';
		return;
	}

	n -= 2;
	int f[][N] = {
		{1, 1},
		{0, 0}
	};
	int A[][N] = {
		{b % 7, 1},
		{a % 7, 0}
	};
	while(n) {
		if(n & 1) mul(f, f, A);
		mul(A, A, A);
		n >>= 1;
	}
	cout << f[0][0] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}