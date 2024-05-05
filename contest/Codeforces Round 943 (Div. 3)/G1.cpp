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
	int n, l, r;
	cin >> n >> l >> r;
	string s;
	cin >> s;
	int low = 0, high = n;
	auto check = [&](int mid) {
		string t = s.substr(0, mid);
		int cnt = 0, i = 0;
		while(cnt < r) {
			cout << i << endl;
			if(s.find(t, i) != string::npos) {
				i = s.find(t, i) + sz(t);
				cnt += 1;
			} else {
				break;
			}
		}
		cout << i << endl;
		cout << cnt << endl;
		return cnt >= r;
	};
	cout << check(19055) << endl;
//	while(low < high) {
//		int mid = (low + high + 1) / 2;
//		if(check(mid)) low = mid;
//		else high = mid - 1;
//	}
//	cout << high << '\n';	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("out.txt", "r", stdin);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;	
}
