#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 200010;

ll s[N], a[N];

void init(int n) {
	ll a = 1, b = 1, c;
	s[0] = 1, s[1] = 2;
	for(int i = 2; i <= n; i++) {
		c = (a + b) % mod;
		s[i] = (s[i - 1] + c) % mod;
		a = b, b = c;
	}
}

/*
	思路： 将 a[i] 看成一个二进制串，每次操作相当于在其末尾加一个 '1' 或者两个 '0'。
		  假设集合里 2^i <= x < 2^(i + 1) 的 x 个数有 f[i] 个，
		  那么 f[i] = f[i - 1] + f[i - 2]。最终 a[i] 产生的数有 
		  sum(f[p - a[i]的二进制位数]) 个，sum(x) 表示从 0 到 x 求和。
		  但是 a[j] 有可能产生的数和别的数 a[i] 有重合，当且仅当 a[i] 的二进制串可以
		  通过若干次操作变成 a[j]，即 a[i] 是 a[j] 的前缀，即 a[i] <= a[j]。因此
		  将 a 数组排序之后用 set 维护所有出现的没有前缀的数，判断当前的数的前缀有没有
		  出现在 set 中，没有出现过就统计当前数的答案。
*/
void solve() {
	ll n, p;
	cin >> n >> p;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	init(p);
	sort(a + 1, a + 1 + n);

	ll ans = 0;
	set<string> st;
	for(int i = 1; i <= n; i++) {
		string str = "";
		int x = a[i];
		while(x) {
			str.push_back(x % 2 + '0');
			x /= 2;
		}
		reverse(str.begin(), str.end());
		if(sz(str) > p) continue;
		
		auto t = str;
		int ok = 1;
		while(sz(str)) {
			if(st.count(str)) {
				ok = 0;
				break;
			}
			if(str.back() == '1') str.pop_back();
			else {
				if(sz(str) == 1 || str[sz(str) - 2] == '1') break;
				str.pop_back();
				str.pop_back();
			}
		}
		if(ok) {
			st.insert(t);
			ans += s[p - sz(t)];
			ans %= mod;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}