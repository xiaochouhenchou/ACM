#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 20;

void get_data() {
	ofstream fout("in.txt");
	int t = 1;
	fout << t << '\n';
	int n = rand() % 8 + 3;
	fout << n << '\n';
	for(int i = 1; i <= n; i++) {
		fout << rand() % N + 1 << " \n"[i == n];
	}
	fout.close();
}

bool test(string s) {
	string out = s + ".txt";
	string e = s + ".exe";
	string str1 = e + " < in.txt > " + out;
	string str2 = "baoli.exe < in.txt > baoli.txt";
	string str3 = "fc baoli.txt " + out;
	system(str1.c_str());
	// system(str2.c_str());
	// return !system(str3.c_str());
	ifstream data("in.txt");
	ifstream ans(out.c_str());
	int n;
	data >> n >> n;
	vector<int> t(n), c(n);
	for(auto &x : t) {
		data >> x;
	}
	int k;
	ans >> k;
	for(auto &x : c) {
		ans >> x;
		if(x < 1 || x > k) return false;
	}
	for(int i = 0; i < n; i++) {
		if(t[i] != t[(i + 1) % n]) {
			if(c[i] == c[(i + 1) % n]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand((unsigned)time(NULL));
	string name = "CF1328D";
	int t = 100;
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