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
	vector<ll> a(n + 1), sum(2, -INF), len(2);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		int t = (a[i] > 0 ? 0 : 1);
		ll tmp = a[i];
		ll length = 1;
		if(len[t] + 1 > length) {
			length = len[t] + 1;
			tmp = sum[t] + a[i];
		} else if(len[t] + 1 == length && sum[t] + a[i] > tmp) {
			tmp = sum[t] + a[i];
		}
		
		t ^= 1;
		if(length > len[t]) {
			len[t] = length;
			sum[t] = tmp;
		} else if(length == len[t] && tmp > sum[t]) {
			sum[t] = tmp;
		}
	}
	if(len[0] != len[1]) {
		cout << (len[0] > len[1] ? sum[0] : sum[1]) << '\n';
	} else {
		cout << max(sum[0], sum[1]) << '\n';
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