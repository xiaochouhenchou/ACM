#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

class Solution {
public:
    int countArrangement(int n) {
        vector<vector<int>> f(n + 1, vector<int>(1 << n));
        vector<vector<vector<int>>> pre(n + 1, vector<vector<int>>(1 << n));
        vector<int> a;
        f[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            a.clear();
            for(int j = 1; j <= i / j; j++) {
            	if(i % j == 0) {
					a.push_back(j);
                	if(i / j != j) a.push_back(i / j);
            	}
            }
            for(int j = i + i; j <= n; j += i) {
                a.push_back(j);
            }
            for(int j = 0; j < (1 << n); j++) {
                for(int x : a) {
                    if(!(j >> (x - 1) & 1)) continue;
                    f[i][j] += f[i - 1][j ^ (1 << (x - 1))];
                    if(f[i - 1][j ^ (1 << (x - 1))]) {
                    	pre[i][j].push_back(j ^ (1 << (x - 1)));
                    }
                }
            }
        }
        return f[n][(1 << n) - 1];
    }
};

void solve() {
	int n;
	cin >> n;
	cout << Solution().countArrangement(n) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}