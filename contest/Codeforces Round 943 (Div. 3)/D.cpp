#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
	int n, k, pb, ps;
	cin >> n >> k >> pb >> ps;
	vector<int> p(n + 1), a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
	}		
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> cb, cs;
	int b = pb, s = ps;
	do {
		cb.push_back(b);
		b = p[b];
	} while(b != pb);
	do {
		cs.push_back(s);
		s = p[s];
	} while(s != ps);

	// for(int i = 0; i < sz(cb); i++) {
	// 	cout << cb[i] << " \n"[i == sz(cb) - 1];
	// }
	// for(int i = 0; i < sz(cs); i++) {
	// 	cout << cs[i] << " \n"[i == sz(cs) - 1];
	// }

	ll ans_b = 0, ans_s = 0;
	{
		ll pre = 0;
		for(int x = 0; x < min(k, sz(cb)); x++) {
			pre += a[cb[x]];
			ans_b = max(ans_b, pre + 1ll * a[cb[x]] * (k - x - 1));
		}
	}
	{
		ll pre = 0;
		for(int x = 0; x < min(k, sz(cs)); x++) {
			pre += a[cs[x]];
			ans_s = max(ans_s, pre + 1ll * a[cs[x]] * (k - x - 1));
		}
	}
	// cout << ans_b << ' ' << ans_s << '\n';
	if(ans_b != ans_s) {
		cout << (ans_b > ans_s ? "Bodya\n" : "Sasha\n");
	} else {
		cout << "Draw\n";
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
