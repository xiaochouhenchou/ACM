#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void get_data() {
	ofstream fout("in.txt");
	// int a = rand() % 1000;
	// int b = rand() % (1000 - a + 1) + a;	
	// int c = rand() % 1000;
	// int d = rand() % (1000 - c + 1) + c;
	int a = 0;
	int b = 3000000;
	int c = 0;
	int d = 3000000;
	fout << a << ' ' << b << ' ' << c << ' ' << d << ' '
	 << 1000000000 << ' ' << 1000000000 << '\n';	
}

bool test() {
	system("E.exe < in.txt > E.txt");
	// system("baoli_E.exe < in.txt > baoli_E.txt");
	// return !system("fc E.txt baoli_E.txt");
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
			cout << "WA! " << endl;
			return 0;
		}
	}
	return 0;	
}
