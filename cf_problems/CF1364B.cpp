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
	vector<int> p(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
	}	
	vector<int> ans;
	for(int i = 1; i <= n; ) {
		int j = i + 1;
		while(j <= n && p[j] > p[j - 1]) j += 1;
		if(j == i + 1) {
			while(j <= n && p[j] < p[j - 1]) j += 1;
		}
		ans.push_back(p[i]);
		if(j - 1 == i) {
			break;
		}
		i = j - 1;
	}
	cout << sz(ans) << '\n';
	for(int i = 0; i < sz(ans); i++) {
		cout << ans[i] << " \n"[i == sz(ans) - 1];
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