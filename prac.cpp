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
	cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    ll ans = 0;
    for(int i = 1; i <= n; ) {
        int j = i + 1, maxv = a[i];
        while(j <= n && (a[j] > 0) == (a[i] > 0)) {
            maxv = max(maxv, a[j]);
            j += 1;
        }
        ans += maxv;
        i = j;
    }
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