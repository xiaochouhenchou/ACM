#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 100010;

int n, k;
int a[N], mp[N];

void solve() {
	cin >> n >> k;	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cnt = 0, ans = inf;
	for(int i = 1, j = 1; i <= n; i++) {
		while(j <= n && cnt < k) {
			if(++mp[a[j]] == 1 && a[j] <= k) {
				cnt += 1;
			}
			j += 1;
		}
		if(cnt >= k) {
			ans = min(ans, j - i);
		}
		if(--mp[a[i]] == 0 && a[i] <= k) {
			cnt -= 1;
		}
	}
	if(ans >= inf) ans = 0;
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