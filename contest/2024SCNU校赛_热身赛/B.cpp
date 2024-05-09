#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

struct node {
	int t;
	vector<int> v;
	bool operator < (const node &no) const {
		return t > no.t;
	}
};

/*
	思路： 重载结构体的小于号，用优先队列模拟过程。
*/
void solve() {
	int n, k;
	cin >> n >> k;
	// [t, r, id]
	vector<tuple<int, int, int>> p(n + 1);
	for(int i = 1, r, t; i <= n; i++) {
		cin >> r >> t;
		p[i] = {t, r, i};
	}
	sort(p.begin() + 1, p.end());

	vector<priority_queue<node>> q(7);
	vector<node> ans;
	for(int i = 1; i <= n; i++) {
		auto [t, r, id] = p[i];
		int rj = ((r - k) % 7 + 7) % 7;
		if(sz(q[rj])) {
			auto no = q[rj].top();
			q[rj].pop();
			no.v.push_back(id);
			if(sz(no.v) < 3) {
				q[r].push(no);
			} else {
				ans.push_back(no);
			}
		} else {
			q[r].push({t, vector<int>{id}});
		}
	}
	sort(ans.begin(), ans.end(), [&](const node &a, const node &b) {
		return a.t < b.t;
	});
	for(auto &no : ans) {
		sort(no.v.begin(), no.v.end());
		for(int i = 0; i < 3; i++) {
			cout << no.v[i] << " \n"[i == 2];
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