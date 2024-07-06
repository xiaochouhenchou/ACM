#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 100;

int n, m, k;
char s[N * 2 + 5][N * 2 + 5];

void solve() {
	cin >> n >> m >> k;
	if(k < n || (k % 2) != n % 2) {
		cout << "No\n";
		return;
	}		

	// k == n 的情况
	for(int i = 0; i <= n * 2; i++) {
		for(int j = 0; j <= m * 2; j++) {
			if(i % 2 == 0) {	// 墙
				if(j == m * 2 - 1) {	// 缺口
					s[i][j] = '.';
				} else if(j % 2 && i != 0 && i != n * 2){
					s[i][j] = '-';
				} else {
					s[i][j] = '+';
				}
			} else {
				if(j % 2 == 0) {
					if(j != 0 && j != m * 2) {
						s[i][j] = '|';
					} else {
						s[i][j] = '+';
					}
				} else {
					s[i][j] = 'o';
				}
			}
		}
	}
	s[0][m * 2 - 1] = 'S';
	s[n * 2][m * 2 - 1] = 'G';

	for(int i = 1; i + 2 < n * 2; i += 4) {
		for(int j = m * 2 - 1; j >= 3; j -= 2) {
			if(k > n) {
				k -= 2;
				s[i + 1][j] = '-';
				s[i][j - 1] = '.';
				s[i + 1][j - 2] = '.';
				s[i + 2][j - 1] = '.';
			}
		}
	}

	if(n % 2) {
		int i = n * 2 - 1;
		for(int j = 1; j + 2 < m * 2; j += 4) {
			if(k > n) {
				k -= 2;
				s[i - 1][j] = '.';
				s[i][j + 1] = '.';
				s[i - 2][j + 1] = '|';
				s[i - 1][j + 2] = '.';
			}
		}
	}

	cout << "Yes\n";
	for(int i = 0; i <= n * 2; i++) {
		cout << s[i] << '\n';
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