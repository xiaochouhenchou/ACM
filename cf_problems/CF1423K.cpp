#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1000005;

bool vis[N];
int ans[N], b[N];
vector<int> p;

// 打表发现只有质数会对答案产生贡献，而当某个质数的平方出现后它也不再产生贡献
void init(int n) {
	vis[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) {
			p.push_back(i);
		}
		for(int j = 0; p[j] <= n / i; j++) {
			vis[p[j] * i] = true;
			if(i % p[j] == 0) {
				break;
			}
		}
	}

	for(int i = 1, cnt = 0; i <= n; i++) {
		cnt += !vis[i];
		ans[i] = cnt + 1;
	}
	for(int x : p) {
		if(x <= n / x) {
			b[x * x] += 1;
			b[n + 1] -= 1;
		} else {
			break;
		}
	}
	for(int i = 1; i <= n; i++) {
		b[i] += b[i - 1];
		ans[i] -= b[i];
	}
}

void solve() {
	int n;
	cin >> n;
	cout << ans[n] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init(1e6);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}