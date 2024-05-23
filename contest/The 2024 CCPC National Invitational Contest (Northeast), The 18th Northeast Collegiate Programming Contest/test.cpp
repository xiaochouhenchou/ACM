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
	int n = 300;
	fout << n << '\n';
	for(int i = 0; i < n; i++) {
		int x = rand() % inf;
		if(rand() % 2) x = -x;
		int y = rand() % inf;
		if(rand() % 2) y = -y;
		fout << x << ' ' << y << '\n';
	}
	fout.close();
}

bool test(string s) {
	string out = s + ".txt";
	string e = s + ".exe";
	string str1 = e + " < in.txt > " + out;
	string str2 = "baoli_" + e + " < in.txt > " + "baoli_" + out;
	string str3 = "fc " + out + " baoli_" + out;
	system(str1.c_str());
	// system(str2.c_str());
	// return !system(str3.c_str());
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand((unsigned)time(NULL));
	string name = "M";
	int t = 1;
	for(int i = 1; i <= t; i++) {
		get_data();
		if(!test(name)) {
			cout << "wa on test " << i << endl;
			return 0;
		} else {
			cout << "ac on test " << i << endl;
		}
	}
	return 0;
}