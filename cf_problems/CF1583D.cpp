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
	思路： 2n 次询问的交互题，可以先用 n 次询问确定某一个特定位置的值，然后再用 n 次
		  询问确定其他位置的值。本题询问返回的是出现次数大于等于 2 的第一个位置，因此
		  先确定 p[n]，再确定其他数即可。
		  1. 确定 p[n]： 枚举 k，询问 kkkk...kkn，如果对于 k < n 询问都没有答案，
		  	 那么 p[n] = n。否则一定存在某个位置 j 使得 p[j] = n，p[n] = k
		  	 p[j] + k = p[n] + n = n + k。这部分最多询问 n - 1 次。
		  2. 确定 p[1...n]： 枚举 i，询问 p[n]p[n]p[n]p[n]...p[n]p[n]i，询问
		  	 返回即为 i 的位置。这部分询问 n 次。
		  总次数为 2n - 1 次。
*/
void solve() {
	int n;
	cin >> n;
	vector<int> p(n + 1);
	auto ask = [&](int x, int y) {
		cout << "?";
		for(int i = 1; i < n; i++) {
			cout << " " << x;
		}
		cout << " " << y << endl;
		int res;
		cin >> res;
		return res;
	};
	for(int k = 1; k < n; k++) {
		int j = ask(k, n);
		if(j != 0) {
			p[n] = k, p[j] = n;
			break;
		}
	}
	if(!p[n]) p[n] = n;
	for(int i = 1; i <= n; i++) {
		p[ask(p[n], i)] = i;
	}
	cout << "!";
	for(int i = 1; i <= n; i++) {
		cout << " " << p[i];
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}