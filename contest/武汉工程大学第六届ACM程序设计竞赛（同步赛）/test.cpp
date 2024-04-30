#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;
const double eps = 1e-8;
const int mod = 1e9 + 9;

void get_data() {
	ofstream fout("in.txt");
	int n = rand() % 100 + 1;
	fout << n << '\n';
	for(int i = 1; i <= n; i++) {
		fout << rand() % inf + 1 << " \n"[i == n];
	}
	fout.close();
}

bool test() {
	system("baoli_D.exe < in.txt > baoli_D.txt");
	system("D.exe < in.txt > D.txt");
	return !system("fc baoli_D.txt D.txt");
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand((unsigned)time(NULL));
	int t = 100;
	for(int i = 0; i < t; i++) {
		get_data();
		if(!test()) {
			cout << "WA! on test " << i << endl;
			return 0;
		}
		cout << "AC on test " << i << endl;
	}
	return 0;
}
