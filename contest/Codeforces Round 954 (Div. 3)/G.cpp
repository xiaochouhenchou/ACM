#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 500000;

vector<int> divisors[N + 1];

void init() {
	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N; j += i) {
			divisors[j].push_back(i);
		}
	}
}

void solve() {
	int n, t = 0;
	cin >> n;
	vector<int> p(n + 1), a(n + 1), b(n + 1), cnt(n + 1);
	vector<vector<int>> mpa(n + 1), mpb(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		int g = __gcd(p[i], i);
		a[i] = p[i] / g;
		b[i] = i / g;
		mpa[a[i]].push_back(i);
		mpb[b[i]].push_back(i);
		t += (p[i] % i == 0);	// i = j 时会重复计算
	}
	ll ans = 0;
	for(int bi = 1; bi <= n; bi++) {
		for(int aj = bi; aj <= n; aj += bi) {
			for(int j : mpa[aj]) {
				cnt[b[j]] += 1;
			}
		}
		for(int i : mpb[bi]) {
			for(int bj : divisors[a[i]]) {
				ans += cnt[bj];
			}			
		}
		for(int aj = bi; aj <= n; aj += bi) {
			for(int j : mpa[aj]) {
				cnt[b[j]] -= 1;
			}
		}
	}
	cout << (ans - t) / 2 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}