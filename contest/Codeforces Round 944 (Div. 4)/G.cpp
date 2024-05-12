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
	vector<int> a(n + 1);
	map<int, set<int>> mp;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]].insert(i);
	}
	for(int i = 1; i <= n; i++) {
		mp[a[i]].erase(i);
		if(!sz(mp[a[i]])) {
			mp.erase(mp.find(a[i]));
		}

		vector<int> tmp;
		for(int j = 0; j < 4; j++) {
			tmp.push_back(a[i] ^ j);
		}
		sort(tmp.begin(), tmp.end());

		int best_aj = a[i];
		for(int x : tmp) {
			if(x >= a[i]) break;
			if(!mp.count(x)) continue;
			best_aj = x;
			break;
		}	
		if(best_aj != a[i]) {
			int j = *(mp[best_aj].begin());
			mp[a[j]].erase(j);
			if(!sz(mp[a[j]])) {
				mp.erase(mp.find(a[j]));
			}
			swap(a[i], a[j]);
			mp[a[j]].insert(j);
		}
		// for(int i = 1; i <= n; i++) {
		// 	cout << a[i] << " \n"[i == n];
		// }
		// for(auto [x, st] : mp) {
		// 	cout << x << '\n';
		// 	for(int y : st) {
		// 		cout << y << ' ';
		// 	}
		// 	cout << '\n';
		// }
		// cout << "---------------\n";
	}
	for(int i = 1; i <= n; i++) {
		cout << a[i] << " \n"[i == n];
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