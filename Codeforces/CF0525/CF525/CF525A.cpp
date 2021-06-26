#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}
 
string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,ans=0;
	string s;
	cin>>n;
	cin>>s;
	map<char,int> keys;
	for (int i=0;i<2*(n-1);i+=2)
	{
		++keys[s[i]-('a'-'A')];
		if (keys[s[i+1]]>0)
		{
			--keys[s[i+1]];
		}
		else
		{
			++ans;
		}
	}
	cout<<ans;
	return 0;
}