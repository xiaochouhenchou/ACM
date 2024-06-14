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
	vector<int> a(n + 1), b(n + 1), s(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		vector<int> t;
		for(int j = 1; j <= n; j++) {
			if(i != j) t.push_back(a[j]);
		}
		int last_b = 0, ok = 1;
		for(int j = 0; j < n - 2; j++) {
			int tmp = __gcd(t[j], t[j + 1]);
			ok &= last_b <= tmp;
			last_b = tmp;
		}
		if(ok) {
			cout << i << '\n';
			for(int j = 0; j < n - 2; j++) {
				cout << __gcd(t[j], t[j + 1]) << " \n"[j == n - 3];
			}
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}