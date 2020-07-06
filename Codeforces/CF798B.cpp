#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool compStr(string s, string t, int n)
{
	for (int i=0;i<n;++i)
	{
		if (s[i]!=t[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,answer=1000000000,cur,lastDone;
	cin>>n;
	string s[n];
	string t;
	for (int i=0;i<n;++i)
	{
		cin>>s[i];
	}
	k=s[0].length();
	if (n==1)
	{
		cout<<0;
		return 0;
	}
	if (k==1)
	{
		for (int i=1;i<n;++i)
		{
			if (!compStr(s[0],s[i],k))
			{
				cout<<-1;
				return 0;
			}
		}
		cout<<0;
		return 0;
	}
	for (int i=0;i<k;++i)
	{
		cur=i;
		lastDone=0;
		for (int j=1;j<n;++j)
		{
			t=s[j];
			for (int z=0;z<k;++z)
			{
				if (compStr(s[0],t,k))
				{
					cur+=z;
					lastDone=j;
					break;
				}
				t=t.substr(1)+t[0];
			}
			if (lastDone!=j)
			{
				cout<<-1;
				return 0;
			}
		}
		s[0]=s[0].substr(1)+s[0][0];
		answer=min(answer,cur);
	}
	cout<<answer;
	return 0;
}