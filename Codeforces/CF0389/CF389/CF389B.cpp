#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	string s[n];
	for (int i=0;i<n;++i)
	{
		cin>>s[i];
	}
	for (int i=0;i<n-2;++i)
	{
		for (int j=0;j<n;++j)
		{
			if (s[i][j]=='#')
			{
				if (j==0||j==n-1)
				{
					cout<<"NO";
					return 0;
				}
				if (!(s[i+1][j]=='#'&&s[i+1][j-1]=='#'&&s[i+1][j+1]=='#'&&s[i+2][j]=='#'))
				{
					cout<<"NO";
					return 0;
				}
				else
				{
					s[i+1][j]='.';
					s[i+1][j-1]='.';
					s[i+1][j+1]='.';
					s[i+2][j]='.';
				}
			}
		}
	}
	for (int i=n-2;i<n;++i)
	{
		for (int j=0;j<n;++j)
		{
			if (s[i][j]=='#')
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}