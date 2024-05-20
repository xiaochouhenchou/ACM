#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

map<int, int> mp;

void get_data() {
	ofstream fout("in.txt");
	int t = 1;
	fout << t << '\n';
	int n = rand() % 20;
	int x = rand() % 100;
	fout << n << ' ' << x << '\n';
	for(int i = 1; i <= n; i++) {
		fout << rand() % 100 << " \n"[i == n];
	}
	fout.close();
}

bool test(string s) {
	string out = s + ".txt";
	string e = s + ".exe";
	string str1 = e + " < in.txt > " + out;
	system(str1.c_str());
	ifstream ans(out.c_str());
	int x;
	ans >> x;
	mp[x] += 1;
	return x <= 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand((unsigned)time(NULL));
	string name = "CF1455";
	int t = 1000;
	for(int i = 1; i <= t; i++) {
		get_data();
		if(!test(name)) {
			cout << "wa on test " << i << endl;
			return 0;
		} else {
			cout << "ac on test " << i << endl;
		}
	}
	for(auto [x, c] : mp) {
		cout << x << ' ' << c << endl;
	}
	return 0;
}