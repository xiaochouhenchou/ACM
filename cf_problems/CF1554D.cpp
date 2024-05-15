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
	思路: aa...aaa，k 个 a 的字符串，如果 k 是奇数，那么每个字符串出现
		 次数分别为奇数、偶数、奇数... 
		 奇数 + 偶数 = 奇数，考虑构造 aaaabaaa（n 是偶数）、aaabcaa（n
		 是奇数）
*/
void solve() {
	int n;
	cin >> n;
	if(n == 1) {
		cout << "a\n";
		return;
	}
	
	if(n % 2 == 0) {
		cout << string(n / 2, 'a') + "b" 
		+ string(n / 2 - 1, 'a') << '\n';
	} else {
		cout << string(n / 2, 'a') + "bc" + 
		string(n / 2 - 1, 'a') << '\n';
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