#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
typedef __int128 LL;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18, N = 1e5;

void get_data() {
	ofstream fout("in.txt");
	ll n = 100;
	ll m = INF;
	fout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i++) {
		ll a = N - i + 1, b = N - i;
		fout << a << ' ' << b << '\n';
	}
	fout.close();
}

bool test() {
	system("D.exe < in.txt > D.txt");
	// ifstream fin("D.txt");
	// ifstream data("in.txt");
	// string s;
	// fin >> s;
	// if(s[0] == 'h') return true;
	// ll res = 0;
	// for(char c : s) {
	// 	res = res * 10 + c - '0';
	// }
	// ll n, m;
	// data >> n >> m;
	// if(res > m) return false;
	// for(int i = 0; i < n; i++) {
	// 	ll a, b;
	// 	data >> a >> b;
	// 	if(res % a != b) return false;
	// }
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand((unsigned)time(NULL));
	int t = 1;
	for(int i = 0; i < t; i++) {
		get_data();
		if(!test()) {
			cout << "WA! " << endl;
			return 0;
		} else {
			cout << "AC " << i << endl;
		}
	}
	return 0;	
}
