#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void print(__int128 x) {
	if(x / 10) print(x / 10);
	cout << int(x % 10);
}

void solve() {
	ll x, k;
	cin >> x >> k;
	set<__int128> st;
	{
		queue<pair<__int128, __int128>> q;
		q.emplace(x, 0);
		while(sz(q)) {
			auto [u, d] = q.front();
			q.pop();
			st.insert(u);

			if(d >= k) continue;
			q.emplace(u * u, d + 1);
			q.emplace(floor(sqrtl(u)), d + 1);
		}
	}
	cout << sz(st) << '\n';
	// for(auto &e : st) print(e), cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}