#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

/*
	思路： 维护两个堆，一个大根堆在下面，一个小根堆在上面，始终保持下面的大根堆
		  的元素都小于上面小根堆的元素，并且大根堆元素个数最多比小根堆多1，
		  最少和小根堆相等。那么中位数就是大根堆的堆顶元素。
*/
void solve() {
	int n;
	cin >> n;
	priority_queue<int> down;
	priority_queue<int, vector<int>, greater<int>> top;
	for(int i = 1, a; i <= n; i++) {
		cin >> a;
		if(!sz(down) || a <= down.top()) {
			down.push(a);
		} else {
			top.push(a);
		}

		while(sz(down) > sz(top) + 1) {
			top.push(down.top());
			down.pop();
		}
		while(sz(top) > sz(down)) {
			down.push(top.top());
			top.pop();
		}
		if(i & 1) {
			cout << down.top() << '\n';
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