#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;

/*
	思路: 每次找一个最大的符合条件的区间操作。
*/
void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	vector<int> pre(n + 2), suf(n + 2, inf);
	vector<int> l(n + 1), r(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<PII> ans;
	auto work = [&](int st, int ed) {
		fill(b.begin(), b.end(), 0);
		for(int i = st; i <= ed; i++) {
			b[a[i]] = 1;
		}
		int idx = st;
		for(int i = 1; i <= n; i++) {
			if(b[i]) a[idx++] = i;
		}
		ans.emplace_back(st, ed);
	};
	while(true) {
		for(int i = 1; i <= n; i++) {
			pre[i] = a[i];
			l[i] = i;
			if(pre[i] < pre[i - 1]) {
				pre[i] = pre[i - 1];
				l[i] = l[i - 1];
			}
		}
		for(int i = n; i; i--) {
			suf[i] = a[i];
			r[i] = i;
			if(suf[i] > suf[i + 1]) {
				suf[i] = suf[i + 1];
				r[i] = r[i + 1]; 
			}
		}
		int L = -1, R = -1, maxv = -inf;
		for(int i = 1; i + 1 <= n; i++) {
			if(pre[i] > suf[i + 1]) {
				if(maxv < r[i + 1] - l[i]) {
					maxv = r[i + 1] - l[i];
					L = l[i], R = r[i + 1];
				}
			}
		}
		if(maxv <= -inf) break;
		work(L, R);
	}
	cout << sz(ans) << '\n';
	for(auto p : ans) {
		cout << p.x << ' ' << p.y << '\n';
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