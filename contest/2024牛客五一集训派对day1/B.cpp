#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 510;

string s[] = {
	"", "COFFEE", "CHICKEN"
};
ll f[N];

void init(int n) {
	f[1] = 6, f[2] = 7;
	for(int i = 3; i <= n; i++) {
		f[i] = f[i - 2] + f[i - 1];
	}
}

void dfs(int n, ll k) {
	if(n < 3) {
		if(k <= sz(s[n])) {
			cout << s[n][k - 1];
		}
		return;
	}

	if(n >= 60 || k <= f[n - 2]) {
		dfs(n - 2, k);
	} else {
		dfs(n - 1, k - f[n - 2]);
	}
}

void solve() {
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i < 10; i++) {
		dfs(n, k + i);
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init(60);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;	
}
