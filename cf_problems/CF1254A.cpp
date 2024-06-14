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
	int r, c, k;
	cin >> r >> c >> k;
	vector<string> s(r), ans(r, string(c, '.'));
	int sum = 0;
	for(auto &str : s) {
		cin >> str;
		sum += count(str.begin(), str.end(), 'R');
	}
	vector<int> v;
	for(int i = 0, re = sum % k; i < k; i++, re -= 1) {
		v.push_back(sum / k + (re > 0));
		// cout << v.back() << " \n"[i == k];
	}
	for(int i = 0, u = 0, cnt = 0; i < r; i++) {
		if(i % 2 == 0) {
			for(int j = 0; j < c; j++) {
				char ch = (u < 26 ? u + 'a' : (u < 52 ? u - 26 + 'A' : u - 52 + '0'));
				ans[i][j] = ch;
				cnt += (s[i][j] == 'R');
				if(cnt >= v[u] && u < k - 1) {
					cnt = 0;
					u += 1;
				}
			}
		} else {
			for(int j = c - 1; j >= 0; j--) {
				char ch = (u < 26 ? u + 'a' : (u < 52 ? u - 26 + 'A' : u - 52 + '0'));
				ans[i][j] = ch;
				cnt += (s[i][j] == 'R');
				if(cnt >= v[u] && u < k - 1) {
					cnt = 0;
					u += 1;
				}
			}			
		}

		cout << ans[i] << '\n';
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