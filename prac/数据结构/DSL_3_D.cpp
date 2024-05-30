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

int n, k;
int a[N];

void solve() {	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	deque<int> q;
	for(int i = 1; i <= n; i++) {
		if(sz(q) && q.front() < i - k + 1) q.pop_front();
		while(sz(q) && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
		if(i >= k) {
			cout << a[q.front()] << " \n"[i == n];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}