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
	思路: 把所有连续的 '*' 段找出来，假设一共有 t 段，每段有 c[i] 个。那么比
		 较两个字符串的字典序相当于比较两个长度为 t 的数列的字典序。 可以把这个
		 数列变成一个混合进制的数，每个数位有 c[i] * k + 1 个选择
		 ([0, c[i] * k])。 找第 x 大字典序的字符串相当于将 x - 1 转化成一个
		 混合进制的数，然后根据这个数输出答案（是 x - 1 而不是 x，因为从 0 开始
		 数的）。
*/
void solve() {
	ll n, k, x;
	string s;
	cin >> n >> k >> x >> s;
	vector<int> c;
	for(int i = 0; i < n; ) {
		if(s[i] != '*') {
			i += 1;
			continue;
		}
		int j = i + 1;
		while(j < n && s[j] == '*') j += 1;
		c.push_back(j - i);
		i = j;
	}

	int t = sz(c);
	vector<int> ans(t);
	x -= 1;
	for(int i = t - 1; i >= 0 && x; i--) {
		ll r = x % (c[i] * k + 1);
		ans[i] = r;
		x /= (c[i] * k + 1);
	}
	for(int i = 0, u = 0; i < n; ) {
		if(s[i] != '*') {
			cout << s[i];
			i += 1;
			continue;
		}
		for(int j = 0; j < ans[u]; j++) {
			cout << 'b';
		}
		i += c[u];
		u += 1;
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