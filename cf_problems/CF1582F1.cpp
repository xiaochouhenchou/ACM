#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 100010, M = 1010;

int n;
int f[N][M], a[N];
int minv[M], vis[M];

/*
	思路: f[i][j] 表示前 i 个数，以第 i 个数为结尾的上升子序列的异或和
		  能否为 j （1 / 0）。
		  f[i][j] |= f[k][j ^ a[i]], a[k] < a[i], 1 <= k < i
		  朴素转移 n^2V，V 为值域。
		  考虑贪心，minv[x] 表示异或和为 x 的上升子序列的末尾元素的最小值，
		  如果 minv[x] < a[i]，那么 f[i][x ^ a[i]] = 1
*/

void solve() {	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	memset(minv, 0x3f, sizeof minv);
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		f[i][a[i]] = 1;
		minv[a[i]] = min(minv[a[i]], a[i]);
		for(int j = 0; j < M; j++) {
			if(minv[j] < a[i] && (j ^ a[i]) < M) {
				f[i][j ^ a[i]] = 1;
				minv[j ^ a[i]] = min(minv[j ^ a[i]], a[i]);
			}
		}
	}
	
	int cnt = 0;
	for(int j = 0; j < M; j++) {
		int ok = 0;
		for(int i = 0; i <= n; i++) {
			if(f[i][j]) {
				// cout << i << ' ' << j << '\n';
				ok = 1;
				break;
			}
		}
		vis[j] = ok;
		cnt += ok;
	}
	cout << cnt << '\n';
	for(int j = 0; j < M; j++) {
		if(vis[j]) cout << j << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}