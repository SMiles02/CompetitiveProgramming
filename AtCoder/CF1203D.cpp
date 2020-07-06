#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<char,int> builder(string g,map<char,int> stringY)
{
	int z=g.length();
	for (int i=0;i<z;++i)
	{
		++stringY[g[i]];
	}
	return stringY;
}

bool compareString(map<char,int> a, map<char,int> b)
{
	string alphabet="abcdefghijklmnopqrstuvwxyz";
	for (int i=0;i<26;++i)
	{
		if (b[alphabet[i]]>a[alphabet[i]])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s,t,adder,alpha,cur;
	int n,m,ans;
	ans=0;
	cin>>s;
	cin>>t;
	n=s.length();
	m=s.length();
	alpha="abcdefghijklmnopqrstuvwxyz";
	cur="";
	map<char,int> occurences;
	map<char,int> stringT;
	for (int i=0;i<26;++i)
	{
		occurences[alpha[i]]=0;
		stringT[alpha[i]]=0;
	}
	for (int i=0;i<m;++i)
	{
		++stringT[t[i]];
	}
	for (int i=0;i<n;++i)
	{
		for (int j=i+1;j<n;++j)
		{
			adder="";
			for (int k=j;k<n;++j)
			{
				adder+=s[k];
			}
			if (compareString(builder(adder,occurences),stringT))
			{
				ans=max(ans,n-(j-i));
			}
			else
			{
				break;
			}
		}
		cur+=s[i];
	}
	cout<<ans;
	return 0;
}