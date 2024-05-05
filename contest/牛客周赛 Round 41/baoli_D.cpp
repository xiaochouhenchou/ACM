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
	vector<string> a;
	auto dfs = [&](auto dfs, int u, string s) -> void {
		if(u == n) {
			a.push_back(s);
			return;
		}

		dfs(dfs, u + 1, s + "r");
		dfs(dfs, u + 1, s + "e");
		dfs(dfs, u + 1, s + "d");
	};
	dfs(dfs, 0, "");
	
	int res = 0;
	auto dfs1 = [&](auto dfs1, int u, string s, string str) -> void {
		if(u >= n) {
			res += s == "red";
			return;
		}

		dfs1(dfs1, u + 1, s, str);
		dfs1(dfs1, u + 1, s + str[u], str);
	};	
	int ans = -1;
	vector<string> v;
	for(auto &str : a) {
		res = 0;
		dfs1(dfs1, 0, "", str);
		if(ans < res) {
			ans = res;
			v = vector<string>{str};
		} else if(ans == res) {
			v.push_back(str);
		}
	}
	cout << ans << '\n';
	for(auto str : v) {
		cout << str << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}