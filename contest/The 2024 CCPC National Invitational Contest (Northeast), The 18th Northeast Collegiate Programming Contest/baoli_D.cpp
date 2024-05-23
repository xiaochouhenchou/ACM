#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 110;

int f[N][N][N];

int dfs(int u, int x, int sum) {
	if(!x) {
		return !sum ? 0 : 1;
	}

	auto &v = f[u][x][sum];
	if(~v) return v;

	if(!u) {
		if(x >= 1 && dfs(u ^ 1, x - 1, sum ^ 1) == 0) return v = 0;
		if(x >= 2 && dfs(u ^ 1, x - 2, sum ^ 2) == 0) return v = 0;  
		if(x >= 3 && dfs(u ^ 1, x - 3, sum ^ 3) == 0) return v = 0; 
		return v = 1; 
	}
	if(x >= 1 && dfs(u ^ 1, x - 1, sum) == 1) return v = 1;
	if(x >= 2 && dfs(u ^ 1, x - 2, sum) == 1) return v = 1;  
	if(x >= 3 && dfs(u ^ 1, x - 3, sum) == 1) return v = 1; 
	return v = 0; 
}

void solve() {
	memset(f, -1, sizeof f);
	for(int i = 1; i <= 100; i++) {
		cout << i << ' ' << dfs(0, i, 0) << '\n';
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