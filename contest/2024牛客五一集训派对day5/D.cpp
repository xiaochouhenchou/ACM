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
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	if(a1 > b1) swap(a1, b1);
	if(a2 > b2) swap(a2, b2);
	if(PII(a1, b1) == PII(2, 8) && PII(a2, b2) != PII(2, 8)) {
		cout << "first\n";
		return;
	}
	if(PII(a2, b2) == PII(2, 8) && PII(a1, b1) != PII(2, 8)) {
		cout << "second\n";
		return;
	}

	if(a1 == b1 && (a2 != b2)) {
		cout << "first\n";
		return;
	}
	if(a2 == b2 && (a1 != b1)) {
		cout << "second\n";
		return;
	}
	if(a1 == b1 && a2 == b2) {
		if(a1 == a2) {
			cout << "tie\n";
		} else {
			cout << (a1 > a2 ? "first\n" : "second\n");
		}
		return;
	}

	int r1 = (a1 + b1) % 10;
	int r2 = (a2 + b2) % 10;
	if(r1 == r2) {
		if(b1 != b2) {
			cout << (b1 > b2 ? "first\n" : "second\n");
		} else {
			cout << "tie\n";
		}
	} else {
		cout << (r1 > r2 ? "first\n" : "second\n");
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