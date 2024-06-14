#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

vector<string> dfs(int k) {
	if(!k) {
		return vector<string>(1, string(1, '#'));
	}

	auto v = dfs(k - 1);
	vector<string> res;
	for(int i = 0; i < sz(v); i++) {
		res.push_back(v[i] + v[i] + v[i]);
	}
	for(int i = 0; i < sz(v); i++) {
		res.push_back(v[i] + string(sz(v), '.') + v[i]);
	}
	for(int i = 0; i < sz(v); i++) {
		res.push_back(v[i] + v[i] + v[i]);
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	auto v = dfs(n);
	for(auto &str : v) {
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