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
	int n;
	string s;
	cin >> n >> s;
	int j = n - 1;
	while(j >= 0 && isalpha(s[j])) {
		j -= 1;
	}
	for(int i = 0; i <= j; i++) {
		if(isalpha(s[i])) {
			cout << "NO\n";
			return;
		}
	}
	for(int i = 1; i <= j; i++) {
		if(s[i] < s[i - 1]) {
			cout << "NO\n";
			return;
		}
	}
	for(int i = j + 1; i < n; i++) {
		if(isdigit(s[i])) {
			cout << "NO\n";
			return;
		}
	}
	for(int i = j + 2; i < n; i++) {
		if(s[i] < s[i - 1]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}