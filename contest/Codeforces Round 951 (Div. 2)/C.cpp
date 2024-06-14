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
	ll n;
	cin >> n;
	vector<ll> k(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
	}

	ll sum = 1e9;
	vector<ll> x(n + 1);
	for(int i = 1; i <= n; i++) {
		x[i] = sum / k[i] + 1;
	}
	
	sum = accumulate(x.begin() + 1, x.end(), 0ll);
	for(int i = 1; i <= n; i++) {
		if(k[i] * x[i] <= sum) {
			cout << -1 << '\n';
			return;
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << x[i] << " \n"[i == n];
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