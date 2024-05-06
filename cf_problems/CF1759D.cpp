// #include <bits/stdc++.h>
// #define x first
// #define y second
// #define sz(x) ((int)x.size())
// using namespace std;

// typedef long long ll;
// typedef pair<int, int> PII;
// const int inf = 0x3f3f3f3f;
// const ll INF = 1e18;
// const int N = 32;

// ll p2[N], p5[N];

// void init(int n) {
// 	p2[0] = p5[0] = 1;
// 	for(int i = 1; i <= n; i++) {
// 		p2[i] = p2[i - 1] * 2;
// 		p5[i] = p5[i - 1] * 5;
// 	}
// }

// ll get(ll x) {
// 	vector<int> cnt(10, 0);
// 	while(x % 2 == 0) cnt[2] += 1, x /= 2;
// 	while(x % 5 == 0) cnt[5] += 1, x /= 5;
// 	return min(cnt[2], cnt[5]);
// }

// void solve() {
// 	ll n, m;
// 	cin >> n >> m;
// 	ll ans = n, z = get(n);
// 	for(int i = 0; i <= 31 && p2[i] <= m; i++) {
// 		for(int j = 0; j <= 31 && p5[j] <= m / p2[i]; j++) {
// 			ll tmp = n * p2[i] * p5[j] * (m / (p2[i] * p5[j]));
// 			ll zero = get(tmp);
// 			if(z < zero) {
// 				ans = tmp;
// 				z = zero;
// 			} else if(z == zero && ans < tmp) {
// 				ans = tmp;
// 			}
// 		}
// 	}
// 	if(ans % 10) ans = n * m;
// 	cout << ans << '\n';
// }

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0), cout.tie(0);
// 	init(N - 1);
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();
// 	return 0;
// }

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
	ll n, m;
	cin >> n >> m;
	int cnt[10] = {0};
	ll x = n;
	while(x % 2 == 0) x /= 2, cnt[2] += 1;
	while(x % 5 == 0) x /= 5, cnt[5] += 1;
	ll k = 1;
	while(cnt[2] != cnt[5]) {
		if(cnt[2] < cnt[5]) {
			if(k * 2 <= m) {
				k *= 2;
				cnt[2] += 1;
			} else {
				break;
			}
		} else {
			if(k * 5 <= m) {
				k *= 5;
				cnt[5] += 1;
			} else {
				break;
			}
		}
	}
	while(k * 10 <= m) {
		k *= 10;
	}
	ll ans = (m / k) * n * k;
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