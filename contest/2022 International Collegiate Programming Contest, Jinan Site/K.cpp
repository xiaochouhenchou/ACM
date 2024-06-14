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
	vector<int> pos(n + 1);
	for(int i = 1, a; i <= n; i++) {
		cin >> a;
		pos[a] = i;
	}
	int cnt = 0;
	for(int i = 1; i <= n; ) {
		int j = i + 1;
		while(j <= n && pos[j] < pos[j - 1]) j += 1;
		i = j;
		cnt += 1;
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}