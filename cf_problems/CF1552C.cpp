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
	思路: 将剩下的点从 1 ~ 2(n - k) 编号，一定是 i -> i + (n - k) 连边
		 最优。 证明详见官方题解。
*/

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> vis(n * 2 + 1), mp(n * 2 + 1);
	vector<PII> chords, point;
	for(int i = 0, x, y; i < k; i++) {
		cin >> x >> y;
		vis[x] = vis[y] = 1;
		if(x > y) swap(x, y);
		chords.emplace_back(x, y);
	}	
	for(int i = 1, cnt = 0; i <= n * 2; i++) {
		if(!vis[i]) mp[++cnt] = i;
	}
	for(int i = 1; i <= n - k; i++) {
		chords.emplace_back(mp[i], mp[i + n - k]);
	}
	// a c b
	auto check = [&](int a, int b, int c) {
		return (a < c && c < b);
	};
	auto get_intersection = [&](int a, int b, int c, int d) {
		// a c b d
		if(check(a, b, c) && !check(a, b, d)) return true;
		if(!check(a, b, c) && check(a, b, d)) return true;
		return false;
	};
	int ans = 0;
	for(int i = 0; i < sz(chords); i++) {
		for(int j = 0; j < sz(chords); j++) {
			if(i == j) continue;
			auto [a, b] = chords[i];
			auto [c, d] = chords[j];
			ans += get_intersection(a, b, c, d);
		}
	}
	cout << ans / 2 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}