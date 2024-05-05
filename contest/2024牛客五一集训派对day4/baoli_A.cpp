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

int f[N][N];

int sg(int x, int y) {
	int &v = f[x][y];
	if(~v) return v;

	int cnt[2] = {0};
	for(int k = 1; k <= x; k++) {
		for(int s = 0; s * k <= y; s++) {
			cnt[sg(x - k, y - s * k)] += 1;
			if(cnt[0]) {
				return v = 1;
			}
		}
	}
	for(int k = 1; k <= y; k++) {
		for(int s = 0; s * k <= x; s++) {
			cnt[sg(y - k, x - s * k)] += 1;
			if(cnt[0]) {
				return v = 1;
			}
		}
	}
	return v = 0;
}

void solve() {
	int n, m;
	cin >> n >> m;
	cout << (sg(n, m) ? "Alice\n" : "Bob\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(f, -1, sizeof f);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;	
}
