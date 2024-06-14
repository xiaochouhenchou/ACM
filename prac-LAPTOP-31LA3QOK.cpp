#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1000000;

int n, m, k;
int p[N + 1];

void solve() {
	cin >> n >> m >> k;
    for(int i = 1, a; i <= n; i++) {
        cin >> a;
        p[a] = 1;
    }

    deque<int> q;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(sz(q) && q.front() < i - m + 1) q.pop_front();
        if(p[i]) {
            q.push_back(i);
        }
        if(sz(q) >= k) {
            ans += 1;
            q.pop_back();
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