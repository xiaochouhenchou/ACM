#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

ull P[] = {
		1000000007,
		1000000009,
		1000000021,
		1000000033
};

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<vector<ull>> h(n + 2, vector<ull>(4));
	vector<vector<ull>> rh(n + 2, vector<ull>(4));
	vector<vector<ull>> p(n + 2, vector<ull>(4, 1));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {
			h[i + 1][j] = h[i][j] * P[j] + s[i] - '0';
			p[i + 1][j] = p[i][j] * P[j];
		}
	}
	reverse(s.begin(), s.end());
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {
			rh[i + 1][j] = rh[i][j] * P[j] + s[i] - '0';
		}
	}
	auto get1 = [&](int l, int r) {
		vector<ull> res(4);
		for(int j = 0; j < 4; j++) {
			res[j] = h[r][j] - h[l - 1][j] * p[r - l + 1][j];
		}
		return res;
	};
	auto get2 = [&](int l, int r) {
		l = n + 1 - l;
		r = n + 1 - r;
		swap(l, r);
		vector<ull> res(4);
		for(int j = 0; j < 4; j++) {
			res[j] = rh[r][j] - rh[l - 1][j] * p[r - l + 1][j];
		}
		return res;
	};
	auto get = [&](int i) {
		auto suf = get1(i + 1, n);
		auto pre = get2(1, i);
		for(int j = 0; j < 4; j++) {
			suf[j] = suf[j] * p[i][j] + pre[j];
		}
		return suf;
	};
	string t1 = "", t2 = "";
	for(int i = 0; i < n / k; i++) {
		t1 += string(k, i % 2 + '0');
		t2 += string(k, !(i % 2) + '0');
	}
	vector<ull> x(4), y(4);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {
			x[j] = x[j] * P[j] + t1[i] - '0';
			y[j] = y[j] * P[j] + t2[i] - '0';
		}
	}
	for(int i = 1; i <= n; i++) {
		auto res = get(i);
		if(res == x || res == y) {
			cout << i << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}