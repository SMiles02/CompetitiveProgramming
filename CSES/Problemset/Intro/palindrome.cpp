#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s,alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ",extra="",ans="";
	cin>>s;
	n=s.length();
	map<char,int> m;
	for (int i=0;i<n;++i)
	{
		++m[s[i]];
		if (!(m[s[i]]%2))
		{
			ans+=s[i];
		}
	}
	for (int i=0;i<26;++i)
	{
		if (m[alphabet[i]]%2)
		{
			if (extra!="")
			{
				cout<<"NO SOLUTION";
				return 0;
			}
			extra+=alphabet[i];
		}
	}
	cout<<ans<<extra;
	n=ans.length();
	for (int i=n-1;i>-1;--i)
	{
		cout<<ans[i];
	}
	return 0;
}