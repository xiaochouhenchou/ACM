#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n, h;
	cin >> n >> h;
	vector<int> a(n);
	for(auto &x : a) {
		cin >> x;
	}

	sort(a.begin(), a.end());
	vector<int> p{2, 2, 3};
	int cnt = 0, ans = 0;
	do {
		auto v = p;
		int cnt = 0;
		ll cur = h;
		for(auto x : a) {
			if(x < cur) {
				cur += x / 2;
				cnt += 1;
			} else {
				ll mul = 1, ok = 0;
				for(int i = sz(v) - 1; i >= 0; i--) {
					mul *= v[i];
					if(cur * mul > x) {
						cur *= mul;
						cnt += 1;
						cur += x / 2;
						ok = 1;
						while(sz(v) > i) v.pop_back();
						break;
					}
				}
				if(!ok) break;
			}
		}
		ans = max(ans, cnt);
	} while(next_permutation(p.begin(), p.end()));

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}