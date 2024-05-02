#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 20010;

int n;
int R[N];
string s;

vector<int> mul(vector<int> &a, int b) {
	vector<int> c;
	int t = 0;
	for(int i = 0; i < sz(a); i++) {
		t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	while(t) {
		c.push_back(t % 10);
		t /= 10;
	}
	return c;
}

vector<int> add(vector<int> &a, vector<int> b) {
	if(sz(a) < sz(b)) return add(b, a);
	vector<int> c;
	int t = 0;
	for(int i = 0; i < sz(a); i++) {
		t += a[i];
		if(i < sz(b)) t += b[i];
		c.push_back(t % 10);
		t /= 10;
	}
	if(t) c.push_back(t);
	return c;
}

vector<int> sub(vector<int> &a, int b) {
	vector<int> c;
	int t = b;
	for(int i = 0; i < sz(a); i++) {
		t = a[i] - t;
		c.push_back((t + 10) % 10);
		if(t < 0) {
			t = 1;
		} else {
			t = 0;
		}
	}
	while(sz(c) > 1 && c.back() == 0) c.pop_back();
	return c;
}

void print(vector<int> v) {
	for(int x : v) {
		cout << x << ' ';
	}
	cout << endl;
}

vector<int> dfs(int l, int r) {
	// cout << l << ' ' << r << endl;
	if(l == r) {
		// cout << ": " << l << ' ' << r << endl;
		return vector<int>{s[r] - '0'};
	}
	
	vector<int> res{0};
	for(int i = l; i <= r; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			if(i + 1 <= r && s[i + 1] == '(') {
				auto t = dfs(i + 1 + 1, R[i + 1] - 1);
				vector<int> m{1};
				while(true) {
					if(sz(t) == 1 && t[0] == 0) break;
					t = sub(t, 1);
					m = mul(m, 2);
				}
				res = add(res, m);
				i = R[i + 1];
			} else {
				int j = i + 1;
				vector<int> t{s[i] - '0'};
				while(j <= r && s[j] != '+') {
					t = mul(t, 10);
					t = add(t, vector<int>{s[j] - '0'});
					j += 1;
				}
				// cout << "add " << i << ' ' << j - 1 << '\n';
				res = add(res, t);
				i = j;
			}
		}
	}
	// print(res);
	// cout << ": " << l << ' ' << r << endl;
	return res;
}

void solve() {
	cin >> s;
	n = sz(s);
	vector<int> stk;
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') stk.push_back(i);
		else if(s[i] == ')') {
			R[stk.back()] = i;
			stk.pop_back();
		}
	}
	auto v = dfs(0, n - 1);
	for(int i = sz(v) - 1; i >= 0; i--) {
		cout << v[i];
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;	
}
