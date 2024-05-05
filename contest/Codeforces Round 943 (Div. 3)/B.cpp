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
	int n, m;
	string a, b;
	cin >> n >> m >> a >> b;
	int k = 0;
	for(int i = 0; i < m && k < n; i++) {
		if(b[i] == a[k]) {
			k += 1;
		}
	}
	cout << k << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;	
}
