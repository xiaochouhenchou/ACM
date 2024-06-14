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
	s = a + b
	s'= b + reverse(a)
	reverse(s') = a + reverse(b)
	s' 是一个合法字符串 <-> reverse(s') 是一个合法字符串
	所以贪心地把 s 开头长度等于 k 的块删掉即可。
*/

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	string x = "", y = "";
	for(int i = 0; i < n / k; i++) {
		x += string(k, i % 2 + '0');
		y += string(k, !(i % 2) + '0');
	}
	
	auto rev = [&](string s) {
		reverse(s.begin(), s.end());
		return s;
	};

	int p = n;
	for(int i = 0; i < n; ) {
		int j = i + 1;
		while(j < n && s[j] == s[i]) {
			j += 1;
		}
		
		int len = j - i;
		if(len == k) {
			i = j;
		} else {
			if(len > k) {
				j -= k;
			}
			string t = s.substr(j) + rev(s.substr(0, j));
			if(t == x || t == y) {
				p = j;
			} else {
				p = -1;
			}
			break;
		}
	}
	cout << p << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}