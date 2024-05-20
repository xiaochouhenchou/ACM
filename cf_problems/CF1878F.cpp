#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1000010;

int minp[N];
vector<int> p;

void init(int n) {
	for(int i = 2; i <= n; i++) {
		if(!minp[i]) {
			minp[i] = i;
			p.push_back(i);
		}
		for(int j = 0; p[j] <= n / i; j++) {
			minp[p[j] * i] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}

void solve() {
	int n, q;
	cin >> n >> q;
	// 将 x 分解质因数存在 map 中
	auto get = [&](int x) {
		map<int, int> res;
		while(x > 1) {
			int y = minp[x], c = 0;
			while(x % y == 0) x /= y, c += 1;
			res[y] = c;
		}
		if(x > 1) res[x] = 1;
		return res;
	};
	// 合并 a、b
	auto merge = [&](map<int, int> &a, map<int, int> b) {
		for(auto [x, c] : b) {
			a[x] += c;
		}
	};
	// 返回 a 的约数个数
	auto calc = [&](map<int, int> &a) {
		int res = 1;
		for(auto [x, c] : a) {
			res *= (c + 1);
		}
		return res;
	};
	// b 是否为 a 的因数
	auto check = [&](map<int, int> &a, int b) {
		for(auto [x, c] : a) {
			if(b % x) continue;
			int cnt = 0;
			while(b % x == 0) b /= x, cnt += 1;
			if(cnt > c) return false;
		}
		return b == 1;
	};

	map<int, int> mp = get(n);
	int dn = calc(mp);
	auto cur = mp;
	while(q--) {
		int k;
		cin >> k;
		if(k == 2) {
			cur = mp;
			dn = calc(cur);
		} else {
			int x;
			cin >> x;
			merge(cur, get(x));
			dn = calc(cur);
			cout << (check(cur, dn) ? "YES\n" : "NO\n");
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init(1e6);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}