#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

int mex(int a, int b) {
	int res = 0;
	while(res == a || res == b) res += 1;
	return res;
}

void solve() {
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	map<vector<int>, int> dis;
	queue<vector<int>> q;
	vector<int> v{a, b, c};
	sort(v.begin(), v.end());
	q.emplace(v);
	dis[v] = 0;
	while(sz(q)) {
		auto t = q.front();
		q.pop();

		{
			vector<int> ne{t[0], t[1], mex(t[0], t[1])};
			sort(ne.begin(), ne.end());
			if(!dis.count(ne)) {
				dis[ne] = dis[t] + 1;
				q.push(ne);
			}
		}
		{
			vector<int> ne{t[0], t[2], mex(t[0], t[2])};
			sort(ne.begin(), ne.end());
			if(!dis.count(ne)) {
				dis[ne] = dis[t] + 1;
				q.push(ne);
			}			
		}
		{
			vector<int> ne{t[1], t[2], mex(t[1], t[2])};
			sort(ne.begin(), ne.end());
			if(!dis.count(ne)) {
				dis[ne] = dis[t] + 1;
				q.push(ne);
			}			
		}
	}
	
	int ans = inf;
	for(auto &[t, d] : dis) {
		if(t[0] == k || t[1] == k || t[2] == k) {
			ans = min(ans, d);
		}
	}
	if(ans == inf) ans = -1;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}