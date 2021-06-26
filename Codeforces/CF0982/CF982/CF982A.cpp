#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin>>n;
	cin>>s;
	if (n==1)
	{
		if (s[0]=='0')
		{
			cout<<"No";
		
		}
		else
		{
			cout<<"Yes";
		}
		return 0;
	}
	for (int i=0;i<n-2;++i)
	{
		if (s[i]==s[i+1]&&s[i]==s[i+2]&&s[i+2]=='0')
		{
			cout<<"No";
			return 0;
		}
	}
	for (int i=0;i<n-1;++i)
	{
		if (s[i]=='1'&&s[i]==s[i+1])
		{
			cout<<"No";
			return 0;
		}
	}
	if (s[n-1]==s[n-2]&&s[n-1]=='0')
	{
		cout<<"No";
		return 0;
	}
	if (s[0]==s[1]&&s[1]=='0')
	{
		cout<<"No";
		return 0;
	}
	cout<<"Yes";
	return 0;
}