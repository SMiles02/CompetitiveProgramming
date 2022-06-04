#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int sieve[100004]={0};
	sieve[0]=1;
	sieve[1]=1;
	sieve[100001]=1;
	sieve[100002]=1;
	for (int i=2;i<100000;++i)
	{
		if (sieve[i]==0)
		{
			for (int j=2;i*j<100001;++j)
			{
				sieve[i*j]=1;
			}
		}
	}
	int n,m,k,cur,mini=1000000000;
	cin>>n>>m;
	int add[n][m];
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			cin>>k;
			for (int z=0;z+k<100004;++z)
			{
				if (sieve[z+k]==0)
				{
					add[i][j]=z;
					break;
				}
			}
		}
	}
	for (int i=0;i<n;++i)
	{
		cur=0;
		for (int j=0;j<m;++j)
		{
			cur+=add[i][j];
		}
		mini=min(cur,mini);
	}
	for (int i=0;i<m;++i)
	{
		cur=0;
		for (int j=0;j<n;++j)
		{
			cur+=add[j][i];
		}
		mini=min(cur,mini);
	}
	cout<<mini;
	return 0;
}