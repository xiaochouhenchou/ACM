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
	vector<vector<int>> e(7);
	for(int i = 1, u, v; i < 6; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	vector<int> cnt(7);
	for(int i = 1; i <= 6; i++) {
		cnt[sz(e[i])] += 1;
	}
	if(cnt[2] == 4 && cnt[1] == 2) {
		cout << "n-hexane\n";
		return;
	}
	if(cnt[1] == 4 && cnt[2] == 1 && cnt[4] == 1) {
		cout << "2,2-dimethylbutane\n";
		return;
	}
	if(cnt[1] == 4 && cnt[3] == 2) {
		cout << "2,3-dimethylbutane\n";
		return;
	}

	fill(cnt.begin(), cnt.end(), 0);
	int u = 1;
	for(int i = 1; i <= 6; i++) {
		if(sz(e[i]) == 3) {
			u = i;
			break;
		}
	}
	for(int v : e[u]) {
		cnt[sz(e[v])] += 1;
	}
	if(cnt[1] == 1) {
		cout << "3-methylpentane\n";
	} else {
		cout << "2-methylpentane\n";
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
