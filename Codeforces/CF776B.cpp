#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int sieve[n+2]={0};
	for (int i=2;i<n+2;++i)
	{
		if (!sieve[i])
		{
			for (int j=2;i*j<n+2;++j)
			{
				sieve[i*j]=1;
			}
		}
		//cout<<"i: "<<i<<" = "<<sieve[i]<<"\n";
	}
	if (n>2)
	{
		cout<<2<<"\n";
	}
	else
	{
		cout<<1<<"\n";
	}
	for (int i=2;i<n+2;++i)
	{
		if (!sieve[i])
		{
			cout<<"1 ";
		}
		else
		{
			cout<<"2 ";
		}
	}
	return 0;
}