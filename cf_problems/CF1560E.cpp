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
	思路: 考虑 s 最后一个被删除的字母是 ch，那么 ch 一定是 t 的最后一个
		 出现的字母。 依此类推，倒数第二个出现的字母就是倒数第二个被删除
		 的字母...至此就能找到所有被删除的字母序列 r。
		 r 中 第 i 个字母是在第 i 次操作被删除的，因此他在 t 中出现了
		 c[i] * i 次，c[i] 为第 i 个字母在初始的 s 中出现的次数。我们
		 无法知道 c[i]，但是我们可以计算出 d[i] = t 中第 i 个字母出现
		 次数，因此 c[i] = d[i] / i，如果不能整除即无解。 否则 s 即为
		 t 的长为 sum(c[i]) 的前缀，验证能否通过 s 得到 t 即可。
*/

void solve() {
	string t;
	cin >> t;
	vector<int> d(26);
	string r = "";
	for(int i = sz(t) - 1; i >= 0; i--) {
		if(++d[t[i] - 'a'] == 1) {
			r.push_back(t[i]);
		}
	}
	reverse(r.begin(), r.end());
	int n = 0;
	for(int i = 0; i < sz(r); i++) {
		if(d[r[i] - 'a'] % (i + 1)) {
			cout << -1 << '\n';
			return;
		}
		n += d[r[i] - 'a'] / (i + 1);
	}
	auto check = [&](string s) {
		string tmp = "";
		for(int i = 0; i < sz(r); i++) {
			tmp += s;
			string ts = "";
			for(char c : s) {
				if(c != r[i]) {
					ts.push_back(c);
				}
			}	
			s = ts;
		}
		return tmp == t;
	};

	string s = t.substr(0, n);
	if(!check(s)) {
		cout << -1 << '\n';
	} else {
		cout << s << ' ' << r << '\n';
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