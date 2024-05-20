#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;

/*
	思路： 打表发现字符串一定是 [([...])] 或者 ([...]) 或者两者拼在一起。
*/
void solve()
{
	cin>>s;
	int f;
	int cnt=0;
	if(s[0]=='('||s[0]==')') f=1;
	else f=0;
	for(int i=1;i<s.length();i++)
	{
		if(f==0&&(s[i]=='('||s[i]==')')) f=1;
		else if(f==1&&(s[i]=='['||s[i]==']')) f=0;
		else
		{
			cnt++;
			if(cnt>2)
			{
				cout<<"No\n";
				return;
			}
		}
	}
	cout<<"Yes\n";
}
int main()
{
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}