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
	int n, d;
	cin >> n >> d;
	vector<int> X(n + 1), Y(n + 1);
	for(int i = 1, a, b; i <= n; i++) {
		cin >> a >> b;
		X[i] = a + b, Y[i] = a - b;
	}
	auto get_ans = [&] {
		map<int, set<PII>> mp;
		tuple<int, int, int> res{0, 0, 0};
		for(int i = 1; i <= n; i++) {
			mp[X[i]].emplace(Y[i], i);
		}
		for(auto &[x, st] : mp) {
			if(mp.find(x + d) != mp.end()) {
				for(auto &[y, i] : st) {
					auto it1 = st.lower_bound(PII(y + d, 0));
					if(it1 == st.end() || it1->x != y + d) continue;
					auto it2 = mp[x + d].lower_bound(PII(y, 0));
					if(it2 == mp[x + d].end() || it2->x > y + d) continue;
					res = {i, it1->y, it2->y};
					// return res;
				}
			}
			if(mp.find(x - d) != mp.end()) {
				for(auto &[y, i] : st) {
					auto it1 = st.lower_bound(PII(y + d, 0));
					if(it1 == st.end() || it1->x != y + d) continue;
					auto it2 = mp[x - d].lower_bound(PII(y, 0));
					if(it2 == mp[x - d].end() || it2->x > y + d) continue;
					res = {i, it1->y, it2->y};
					// return res;
				}
			}
		}
		return res;
	};

	auto [a, b, c] = get_ans();
	if(a != 0) {
		cout << a << ' ' << b << ' ' << c << '\n';
		return;
	}
	
	swap(X, Y);
	auto [A, B, C] = get_ans();
	cout << A << ' ' << B << ' ' << C << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}