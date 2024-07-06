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
	bfs 搜索
*/
void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	s += "..";
	t += "..";
	n += 2;
	
	int ans = -1;
	map<string, int> dis;
	{
		queue<string> q;
		q.emplace(s);
		dis[s] = 0;
		while(sz(q)) {
			auto str = q.front();
			q.pop();

			if(str == t) {
				ans = dis[str];
				break;
			}

			int k = -1;
			for(int i = 0; i < n; i++) {
				if(str[i] == '.') {
					k = i;
					break;
				}
			}

			for(int i = 0; i + 1 < n; i++) {
				if(str[i] != '.' && str[i + 1] != '.') {
					auto ne = str;
					ne[k] = str[i];
					ne[k + 1] = str[i + 1];
					ne[i] = ne[i + 1] = '.';
					if(dis.find(ne) == dis.end()) {
						dis[ne] = dis[str] + 1;
						q.emplace(ne);
					}
				}
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}