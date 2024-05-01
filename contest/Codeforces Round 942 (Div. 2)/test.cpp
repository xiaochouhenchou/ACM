#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void get_data() {
	ofstream fout("in.txt");
	fout << 1 << '\n';
	int n = 2000000;
	int m = 2000000;
	fout << n << ' ' << m << '\n';
	fout.close();
}

bool test() {
	system("D.exe < in.txt > D.txt");
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand((unsigned)time(NULL));
	int t = 1;
	for(int i = 1; i <= t; i++) {
		get_data();
		if(!test()) {
			cout << "WA! on " << test << ' ' << i << endl;
			return 0;
		}
	}
	return 0;	
}
