#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

bool check(int x) {
	if(x % 7 == 0) return true;
	string s = to_string(x);
	return count(s.begin(), s.end(), '7') != 0;
}

void solve() {
	int n, a, k;
	cin >> n >> a >> k;
	a += 1;
	for(int i = 0; i < k; i++) {
		if(check(a)) cout << "p ";
		else cout << a << ' ';
		a += n;
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}