#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) {
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

ll ceil(ll x, ll y) {
	return x >= 0 ? (x + y - 1) / y : x / y;
}

ll floor(ll x, ll y) {
	return x >= 0 ? x / y : (x + y - 1) / y;
}

void solve() {
	ll n, k, x, y;
	cin >> n >> k;
	ll a = n / k, b = (n + k - 1) / k;
	ll cnt1 = k - n % k, cnt2 = n % k;
	ll c = n / 2;
	ll d = exgcd(a, b, x, y);
	if(c % d) {
		cout << "No\n";
		return;
	}
	x *= c / d, y *= c / d;
	b /= d, a /= d;
	ll l = ceil(-x, b), r = floor(cnt1 - x, b);
	ll L = ceil(y - cnt2, a), R = floor(y, a);
	if(l > r || L > R || r < L || l > R) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}