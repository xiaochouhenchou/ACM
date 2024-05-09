#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 10;

void get_data() {
	ofstream fout("in.txt");
	ll n = rand() % 10 + 1;
	ll m = rand() % 10 + 1;
	fout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m; j++) {
			fout << (rand() % 2 ? '.' : '*');
		}
		fout << '\n';
	}
	fout.close();
}

bool test(string c) {
	string str1 = c + ".exe < in.txt > " + c + ".txt";
	string str2 = "baoli_" + c + ".exe < in.txt > baoli_" + c + ".txt";
	string str3 = "fc " + c + ".txt baoli_" + c + ".txt";
	system(str1.c_str());
	system(str2.c_str());
	return !system(str3.c_str());
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand((unsigned)time(NULL));
	int t = 100;
	for(int i = 1; i <= t; i++) {
		get_data();
		if(!test("C")) {
			cout << "WA! on test " << i << endl;
			return 0; 
		}
	}
	return 0;
}