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
	思路: 考虑 n^2 解法，先枚举左括号的起始位置 l = 1, 3, ..., 
		 再往右边扩展。 
		 令直接由当前左括号与它对应右括号产生的贡献为直接贡献，
		 如 () 就是直接贡献。
		 令由当前左括号开始的合法括号序列和它右边的合法括号序列拼接产生的贡献为
		 间接贡献，如 () (()) 产生的贡献即为间接贡献。
		 往右边的扩展的同时，维护一个除了 l 以外的左括号的数量 cnt。如果遇到左括号，
		 cnt += c[r]；如果遇到右括号，如果 cnt > 0，那么从右括号 c[r] 中拿出
		 足够数量的右括号与 cnt 对应的全部左括号匹配，就可以产生 1 的间接贡献。 如
		 果当前右括号还有剩余，那么继续与 c[l] 匹配，产生直接贡献。
*/
void solve() {
	int n;
	cin >> n;
	vector<ll> c(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	ll ans = 0;
	for(int l = 1; l <= n; l += 2) {
		ll cnt = 0;	// 除了 l 以外的左括号的数量
		for(int r = l + 1; r <= n; r++) {	
			if(r & 1) {
				cnt += c[r];
			} else {
				ll tmp = c[r];
				if(cnt != 0) {
					if(tmp < cnt) {
						cnt -= tmp;
						continue;
					} else {
						tmp -= cnt;
						cnt = 0;
						ans += 1;	// 间接贡献
					}
				}
				ans += min(c[l], tmp);	// 直接贡献
				if(c[l] < tmp) break;
				c[l] -= tmp;
			}
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