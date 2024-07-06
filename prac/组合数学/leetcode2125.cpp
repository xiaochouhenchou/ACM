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
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> cnt(n);
        for(int i = 0; i < n; i++) {
        	cnt[i] = count(bank[i].begin(), bank[i].end(), '1');
        }
        int ans = 0;
        for(int i = 0; i < n; ) {
        	if(!cnt[i]) {
                i += 1;
                continue;
            }

        	int j = i + 1;
        	while(j < n && !cnt[j]) j += 1;
        	if(j >= n) break;

        	ans += cnt[i] * cnt[j];
        	i = j;
        }
        return ans;
    }
};

int main() {
	Solution s;
	vector<string> bank = {
		"011001",
		"000000",
		"010100",
		"001000"
	};
	cout << s.numberOfBeams(bank) << '\n';
}
