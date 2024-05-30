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
	int a, b;
	cin >> a >> b;
	int n = 1;
	while(1ll * n * (n + 1) / 2 <= a + b) {
		n += 1;
	}

	if(!a || !b) {
		if(!a) {
			cout << 0 << '\n' << n - 1 << '\n';
			for(int i = 1; i < n; i++) {
				cout << i << " \n"[i == n - 1];
			}
		} else {
			cout << n - 1 << '\n';
			for(int i = 1; i < n; i++) {
				cout << i << " \n"[i == n - 1];
			}
			cout << 0 << '\n';		
		}
		return;
	}

	int sum = 0;
	set<int> p, q;
	for(int i = 1; i < n; i++) {
		if(sum + i <= a) {
			sum += i;
			p.emplace(i);
		} else if(sum + i - a < i) {
			int tmp = sum + i - a;
			p.emplace(i);
			p.erase(tmp);
			q.emplace(tmp);
			while(++i < n) q.emplace(i);
		} else {
			while(i < n) q.emplace(i++);
		}
	}
	cout << sz(p) << '\n';
	for(int x : p) cout << x << ' ';
	cout << '\n';
	cout << sz(q) << '\n';
	for(int x : q) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}