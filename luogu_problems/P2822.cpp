#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 2000;

int k;
int c[N + 1][N + 1], s[N + 1][N + 1];

void init() {
	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= i; j++) {
			if(!j) c[i][j] = 1;
			else {
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
			}
		}
	}
	s[0][0] = !c[0][0];
	for(int j = 1; j <= N; j++) {
		s[0][j] = s[0][j - 1];
	}
	for(int i = 1; i <= N; i++) {
		s[i][0] = s[i - 1][0] + (!c[i][0]);
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] 
			+ (!c[i][j] && j <= i);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	cout << s[n][min(n, m)] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t >> k;
	init();
	while(t--) solve();
	return 0;
}