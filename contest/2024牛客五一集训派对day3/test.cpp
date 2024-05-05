#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) ((int)x.size())
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1000010;

bool vis[N];
vector<int> p;

void init(int n) {
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) {
			p.push_back(i);
		}
		for(int j = 0; p[j] <= n / i; j++) {
			vis[p[j] * i] = 1;
			if(i % p[j] == 0) break;
		}
	}
}

void get_data() {
	ofstream fout("in.txt");
	int t = 1;	
	fout << t << '\n';
	int P = p[rand() % sz(p)];
	fout << P << '\n';
	fout.close();
}

bool test() {
	system("A.exe < in.txt > A.txt");
	ifstream fin("A.txt");
	ifstream data("in.txt");
	int P = 0, x = 0;
	data >> P >> P;
	vector<int> a;
	while(fin >> x) a.push_back(x);
	if(x == -1) {
		return true;
	}
	vector<int> vis(P);
	for(int i = 0; i < sz(a); i++) {
		vis[a[i]] = 1;
	}
	for(int i = 1; i < P; i++) {
		if(!vis[i]) {
			cout << i << '\n';
			cout << "is not a permutation!\n";
			return false;
		}
	}

	for(int i = 0; i + 1 < sz(a); i++) {
		if(a[i + 1] % P != a[i] * 2 % P && a[i + 1] % P != a[i] * 3 % P) {
			cout << a[i + 1] << ' ' << a[i] << '\n';
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init(N - 1);
	int t = 100;
	for(int i = 0; i < t; i++) {
		get_data();
		if(!test()) {
			cout << "WA! \n";
			return 0;
		} else { 
			cout << "AC " << endl;
		}
	}
	return 0;	
}
