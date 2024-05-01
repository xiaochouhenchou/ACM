#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef __int128 LL;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void turn(char &c) {
	c = (c == 'U' ? 'D' : 'U');
}

int dfs(string s) {	// 返回当前局面是否会赢？ 1 : 0
	if(!sz(s)) {
		return 0;
	}

	int n = sz(s);
	for(int i = 0; i < sz(s); i++) {
		if(s[i] == 'U') {
			turn(s[(i - 1 + n) % n]);
			turn(s[(i + 1) % n]); 
			auto t = s.substr(0, i) + s.substr(i + 1);
			if(!dfs(t)) return 1;
			turn(s[(i + 1) % n]);
			turn(s[(i - 1 + n) % n]);
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for(int i = 0; i < 20; i++) {
		int n = rand() % 10 + 1;
		string s = "";
		for(int j = 0; j < n; j++) {
			s.push_back(rand() % 2 ? 'U' : 'D');
		}
		cout << s << '\n' << dfs(s) << '\n' << count(s.begin(), s.end(), 'U')
		 << "--------------\n";
	}
	return 0;	
}
