#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,ans=0;
	cin>>n;
	int a[n];
	cin>>a[0];
	for (int i=1;i<n;++i)
	{
		cin>>a[i];
		if (a[i]==1)
		{
			if (a[i-1]==2)
			{
				ans+=3;
			}
			else
			{
				ans+=4;
			}
		}
		else if (a[i]==2)
		{
			if (a[i-1]==1)
			{
				ans+=3;
			}
			else
			{
				cout<<"Infinite";
				return 0;
			}
		}
		else
		{
			if (a[i-1]==1)
			{
				ans+=4;
			}
			else
			{
				cout<<"Infinite";
				return 0;
			}
		}
	}
	for (int i=0;i<n-2;++i)
	{
		if (a[i]==3)
		{
			if (a[i+1]==1)
			{
				if (a[i+2]==2)
				{
					--ans;
				}
			}
		}
	}
	cout<<"Finite\n"<<ans;
	return 0;
}