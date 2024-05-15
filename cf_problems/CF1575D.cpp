#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

/*
	思路: 暴搜，或者直接枚举能被 25 整除的、位数和 s 相同的数判断是否合法
*/
void solve1() {
	string s;
	cin >> s;
	int n = sz(s);
	if(n == 1) {
		cout << !(s[0] >= '1' && s[0] <= '9') << '\n';
		return;
	}

	vector<int> idx;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'X') idx.push_back(i);
	}
	auto dfs = [&](auto dfs, int u, int num) -> int {
		if(u == n) {
			return !num;
		}

		if(s[u] != '_') {
			num = (num * 10 + s[u] - '0') % 25;
			return dfs(dfs, u + 1, num);
		}

		int res = 0;
		for(int i = 0; i < 10; i++) {
			res += dfs(dfs, u + 1, (num * 10 + i) % 25);
		}
		return res;
	};
	auto get_ans = [&] {
		int res = 0;
		if(s[0] == '_') {
			for(int i = 1; i < 10; i++) {
				res += dfs(dfs, 1, i);
			}
		} else if(s[0] != '0') {
			res += dfs(dfs, 1, s[0] - '0');
		}
		return res;
	};

	int ans = 0;
	if(!sz(idx)) {
		ans += get_ans();
	} else {
		for(int j = 0; j < 10; j++) {
			for(int x : idx) {
				s[x] = j + '0';
			}
			ans += get_ans();
		}
	}
	cout << ans << '\n';
}

void solve2() {
	string s;
	cin >> s;
	int n = sz(s);
	int r = 1, ans = 0;
	for(int i = 0; i < n; i++) r *= 10;
	int l = r / 10;
	if(n == 1) l = 0;
	for(int i = (l + 24) / 25 * 25; i < r; i += 25) {
		string t = to_string(i);
		int x = -1, ok = 1;
		for(int j = 0; j < n; j++) {
			if(s[j] == '_') {

			} else if(s[j] == 'X') {
				if(x == -1) x = t[j] - '0';
				else if(x != t[j] - '0') ok = 0;
			} else {
				ok &= s[j] == t[j];
			}
		}
		ans += ok;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve2();
	return 0;
}