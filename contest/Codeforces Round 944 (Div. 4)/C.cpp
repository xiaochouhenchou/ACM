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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a > b) swap(a, b);
	set<int> st1, st2;
	for(int i = a; i <= b; i++) {
		st1.insert(i);
	}
	for(int i = 1; i <= 12; i++) {
		if(!st1.count(i)) {
			st2.insert(i);
		}
	}
	if((st1.count(c) && st2.count(d)) 
		|| (st1.count(d) && st2.count(c))) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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