#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 200000;

int minp[N + 1], a1[N + 1], a2[N + 1], app[N + 1];
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
	for(int x : p) {
		a1[x] = a2[x] = inf;
	}
}

void fac(int x) {
	while(x > 1) {
		int p = minp[x], cnt = 0;
		while(x % p == 0) x /= p, cnt += 1;
		app[p] += 1;
		if(a1[p] >= cnt) {
			a2[p] = a1[p];
			a1[p] = cnt;
		} else if(a2[p] > cnt) {
			a2[p] = cnt;
		}
	}
}

ll get(int p, int c) {
	ll res = 1;
	while(c--) {
		res *= p;
	}
	return res;
}

void solve() {
	init(N);
	int n;
	cin >> n;
	for(int i = 0, a; i < n; i++) {
		cin >> a;
		fac(a);
	}
	ll g = 1;
	for(int x : p) {
		for(int i = 0; i < min(n - app[x], 2); i++) {
			if(a1[x] >= 0) {
				a2[x] = a1[x];
				a1[x] = 0;
			} else if(a2[x] > 0) {
				a2[x] = 0;
			}
		}
		
		g *= get(x, max(a1[x], a2[x]));
	}
	cout << g << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}