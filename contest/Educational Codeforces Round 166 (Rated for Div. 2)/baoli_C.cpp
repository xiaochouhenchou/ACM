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
	int n, m;
	cin >> n >> m;
	int len = n + m + 1;
	vector<int> a(len + 2), b(len + 2);
	for(int i = 1; i <= len; i++) {
		cin >> a[i];
	} 
	for(int i = 1; i <= len; i++) {
		cin >> b[i];
	}
	for(int j = 1; j <= len; j++) {
		int x = n, y = m;
		ll res = 0;
		for(int i = 1; i <= len; i++) {
			if(i == j) continue;
			if(a[i] > b[i]) {
				if(x) {
					res += a[i];
					x -= 1;
				} else {
					res += b[i];
				}
			} else {
				if(y) {
					res += b[i];
					y -= 1;
				} else {
					res += a[i];
				}
			}
		}
		cout << res << " \n"[j == len];
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