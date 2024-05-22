#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	map<PII, map<int, int>> mp1, mp2, mp3;
	for(int i = 1; i <= n - 2; i++) {
		mp1[{a[i], a[i + 1]}][a[i + 2]] += 1;
		mp2[{a[i + 1], a[i + 2]}][a[i]] += 1;
		mp3[{a[i], a[i + 2]}][a[i + 1]] += 1;
	}
	ll ans = 0;
	for(auto &mp : {mp1, mp2, mp3}) {
		for(auto &p : mp) {
			ll sum = 0;
			for(auto &[x, c] : p.y) {
				sum += c;
			}
			for(auto &[x, c] : p.y) {
				ans += c * (sum - c);
				sum -= c;
			}
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