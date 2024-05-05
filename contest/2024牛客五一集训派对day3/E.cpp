#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n + 1), sum(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i]= sum[i - 1] + a[i];
	}
	auto check = [&](ll mid) {
		for(int i = 1; i <= n; i++) {
			if(mid * i - sum[i] < 0) return false;
		}
		return true;
	};
	ll l = 1, r = *max_element(a.begin(), a.end());
	while(l < r) {
		ll mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << r << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;	
}
