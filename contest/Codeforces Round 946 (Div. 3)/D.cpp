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
	string s;
	cin >> n >> s;
	int dx = 0, dy = 0, cnt0 = 0, cnt1 = 0;
	vector<vector<int>> v(4);	// N S E W
	for(int i = 0; i < n; i++) {
		auto c = s[i];
		if(c == 'N' || c == 'S') {
			dx += (c == 'N' ? 1 : -1);
			cnt0 += 1;
			if(c == 'N') v[0].push_back(i);
			else v[1].push_back(i);
		}
		if(c == 'W' || c == 'E') {
			dy += (c == 'E' ? 1 : -1);
			cnt1 += 1;
			if(c == 'E') v[2].push_back(i);
			else v[3].push_back(i);
		}
	}

	if(dx % 2 || dy % 2) {
		cout << "NO\n";
		return;
	}

	string ans = string(n, 'R');
	if(!dx && !dy) {
		if(cnt0 >= 4) {
			ans[v[0].front()] = ans[v[1].front()] = 'H';
		} else if(cnt1 >= 4) {
			ans[v[2].front()] = ans[v[3].front()] = 'H';
		} else {
			if(cnt0 && cnt1) {
				ans[v[0].front()] = ans[v[1].front()] = 'H';
			} else {
				cout << "NO\n";
				return;
			}
		}
	} else {
		if(dx) {
			int t = dx / 2;
			if(t < 0) {
				for(int i = 0; i < n && t != 0; i++) {
					if(s[i] == 'S') {
						ans[i] = 'H';
						t += 1;
					}
				}
	 		} else {
	 			for(int i = 0; i < n && t != 0; i++) {
	 				if(s[i] == 'N') {
	 					ans[i] = 'H';
	 					t -= 1;
	 				}
	 			}
			}
		}
		if(dy) {
			int t = dy / 2;
			if(t < 0) {
				for(int i = 0; i < n && t != 0; i++) {
					if(s[i] == 'W') {
						ans[i] = 'H';
						t += 1;
					}
				}
	 		} else {
	 			for(int i = 0; i < n && t != 0; i++) {
	 				if(s[i] == 'E') {
	 					ans[i] = 'H';
	 					t -= 1;
	 				}
	 			}
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}