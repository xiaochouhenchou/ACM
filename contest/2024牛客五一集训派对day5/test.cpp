#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void get_data() {
	ofstream fout("in.txt");
	int n = rand() % 10 + 1;
	int k = rand() % n + 1;
	fout << n << ' ' << k << '\n';
	vector<int> p(n);
	iota(p.begin(), p.end(), 1);
	random_shuffle(p.begin(), p.end());
	for(int i = 0; i < k; i++) {
		fout << p[i] << ' ' << rand() % n + 1 << '\n';
	}
}

bool test() {
	system("K.exe < in.txt > K.txt");
	ifstream data("in.txt");
	ifstream fin("K.txt");
	int n, k;
	data >> n >> k;
	vector<int> b(n + 1), a(n + 1);
	for(int i = 1, p, x; i <= k; i++) {
		data >> p >> x;
		b[p] = x;
	}
	fin >> a[1];
	if(a[1] == -1) return true;
	for(int i = 2; i <= n; i++) {
		fin >> a[i];
	}

	vector<int> stk;
	for(int i = 1; i <= n; i++) {
		while(sz(stk) && a[stk.back()] > a[i]) stk.pop_back();
		stk.push_back(i);
		if(b[i] && sz(stk) != b[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 100;
	for(int i = 1; i <= t; i++) {
		get_data();
		if(!test()) {
			cout << "WA! on test " << i << endl;
			return 0;
		} else {
			cout << "AC! on test " << i << endl;
		}
	}
	return 0;
}