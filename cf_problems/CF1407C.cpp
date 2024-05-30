#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

/*
	a[i] % a[j] = x
	a[j] % a[i] = y
	if x > y :
		y = a[j] % a[i] < a[i] = x
	if x < y :
		x = a[i] % a[j] < a[j] = y
*/
void solve() {
	int n;
	cin >> n;
	auto ask = [&](int i, int j) {
		cout << "? " << i << ' ' << j << endl;
		int x;
		cin >> x;
		return x;
	};	
	vector<int> a(n + 1);
	int mx = 1;
	for(int i = 2; i <= n; i++) {
		int x = ask(mx, i);
		int y = ask(i, mx);
		if(x > y) {
			a[mx] = x;
			mx = i;
		} else {
			a[i] = y;
		}
	}
	a[mx] = n;
	cout << "!";
	for(int i = 1; i <= n; i++) {
		cout << " " << a[i];
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}