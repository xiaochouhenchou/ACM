#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

/*
	思路： 找最小的数 x 使得 n ^ x >= m + 1，贪心地按位构造 x。
		  即 n ^ x 的二进制中每一位都满足 a 都大于等于 m + 1 中的
		  每一位 b
*/
void solve() {
	int n, m;
	cin >> n >> m;
	m += 1;
	int ans = 0;
	for(int i = 30; i >= 0; i--) {
		int a = n >> i & 1;
		int b = m >> i & 1;
		if(a != b) {
			if(a == 1) break;	// 1 0
			ans |= 1 << i;		// 0 1
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}