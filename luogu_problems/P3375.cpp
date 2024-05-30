#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

struct KMP {
	int m, n;
	string p, q;
	vector<int> ne;
	KMP() {}
	KMP(const string &s, const string &t) : p(s), q(t) {
		m = sz(s);
		n = sz(t);
		p = " " + p;
		q = " " + q;
		ne.resize(n + 1, 0);
		init();
	}
	void init() {
		for(int i = 2, j = 0; i <= n; i++) {
			while(j && q[i] != q[j + 1]) j = ne[j];
			if(q[i] == q[j + 1]) {
				j += 1;
			}
			ne[i] = j;
		}
	}
	vector<int> match() {
		vector<int> res;
		for(int i = 1, j = 0; i <= m; i++) {
			while(j && p[i] != q[j + 1]) j = ne[j];
			if(p[i] == q[j + 1]) {
				j += 1;
			}
			if(j == n) {
				res.push_back(i - n + 1);
				j = ne[j];
			}
		}
		return res;
	}
};

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	KMP p(s1, s2);
	auto v = p.match();
	for(int x : v) 
		cout << x << '\n';
	for(int i = 1; i <= sz(s2); i++) {
		cout << p.ne[i] << " \n"[i == sz(s2)];
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