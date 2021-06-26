#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin>>s;
	n=s.length();
	if (n==1)
	{
		n=0;
	}
	else if (n%2==1)
	{
		int oneCount=0;
		for (int i=0;i<n;++i)
		{
			if (s[i]=='1')
			{
				++oneCount;
			}
		}
		if (oneCount==1)
		{
			--n;
		}
		else
		{
			++n;
		}
	}
	cout<<n/2;
	return 0;
}