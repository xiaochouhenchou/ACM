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
	vector<int> a(n + 1), b(n + 1);
	map<int, int> mp1;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		mp1[b[i]] += 1;
	}
	int m;
	cin >> m;
	vector<int> d(m + 1);
	map<int, int> mp2;
	for(int i = 1; i <= m; i++) {
		cin >> d[i];
		mp2[d[i]] += 1;
	}
	int cnt = 0, ok = 1;
	for(int i = m; i; i--) {
		if(mp1.find(d[i]) != mp1.end()) {
			cnt += 1;
		} else if(!cnt) {
			ok = 0;
			break;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] != b[i]) {
			if(mp2.find(b[i]) == mp2.end()) {
				ok = 0;
				break;
			}
			if(--mp2[b[i]] == 0) {
				mp2.erase(mp2.find(b[i]));
			}
		}
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}