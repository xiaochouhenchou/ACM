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
	思路： x / y = t，先枚举 y，再枚举 t，那么 x 的范围为 
		  min(t * y, (t + 1) * y - 1)，如果有 x 出现
		  在这个范围，但是 t 没有出现，答案即为 no。最后没
		  有这样的情况答案即为 Yes。 复杂度为调和级数。
*/
void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> a(n + 1), cnt(c + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] += 1;
	}
	for(int i = 1; i <= c; i++) {
		cnt[i] += cnt[i - 1];
	}
	auto app = [&](int x) {
		return cnt[x] - cnt[x - 1];
	};
	for(int y = 1; y <= c; y++) {
		if(!app(y)) continue;
		for(int t = 1; t * y <= c; t++) {
			int l = t * y, r = min((t + 1) * y - 1, c);
			if(cnt[r] - cnt[l - 1] > 0) {
				if(!app(t)) {
					cout << "No\n";
					return;
				}
			}
		}
	}
	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}