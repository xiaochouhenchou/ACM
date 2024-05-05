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
	int t = 1;
	fout << t << '\n';
	while(t--) {
		fout << rand() % 500 + 1 << ' ' << rand() % 500 + 1 << '\n';
	}
	fout.close();		
}

bool test() {
	system("A.exe < in.txt > A.txt");
	system("baoli_A.exe < in.txt > baoli_A.txt");
	return !system("fc A.txt baoli_A.txt");
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand((unsigned)time(NULL));
	int t = 100;
	for(int i = 1; i <= t; i++) {
		get_data();
		if(!test()) {
			cout << "WA! on test " << i << endl;
			return 0;
		}
	}
	return 0;	
}
