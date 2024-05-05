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
	if(n == 2) {
		cout << 1 << ' ' << 1 << '\n';
		cout << 1 << ' ' << 2 << '\n';
		return;
	}
	
	for(int i = 0; i < n - 2; i++) {
		cout << 1 << ' ' << i + 1 << '\n';
	}
	cout << n << ' ' << 2 << '\n';
	cout << n << ' ' << n << '\n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;	
}