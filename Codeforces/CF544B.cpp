#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,f;
	string s,land="L";
	cin>>n>>k;
	if (n==1)
	{
		if (k==1)
		{
			cout<<"YES\nL";
		}
		else if (k==0)
		{
			cout<<"YES\nS";
		}
		else
		{
			cout<<"NO";
		}
		return 0;
	}
	f=n*n;
	if (n%2)
	{
		++f;
	}
	f/=2;
	if (k>f)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	if (1)
	{
		for (int i=0;i<n;++i)
		{
			if (i%2==0)
			{
				for (int j=0;j<n;++j)
				{
					if (!(j%2))
					{
						if (k==0)
						{
							land="S";
						}
						cout<<land;
						--k;
					}
					else
					{
						cout<<"S";
					}
				}
			}
			else
			{
				for (int j=0;j<n;++j)
				{
					if (j%2)
					{
						if (k==0)
						{
							land="S";
						}
						cout<<land;
						--k;
					}
					else
					{
						cout<<"S";
					}
				}
			}
			cout<<"\n";
		}
		return 0;
	}
	return 0;
}