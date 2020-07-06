#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,x;
	cin>>n>>x;
	int c[n];
	for (int i=0;i<n;++i)
	{
		cin>>c[i];
	}
	int dp[x+1]={0};
	for (int i=1;i<=x;++i)
	{
		for (int j=0;j<n;++j)
		{
			if (i-c[j]>0)
			{
				if (dp[i-c[j]]>0)
				{
					if (dp[i])
					{
						dp[i]=min(dp[i],dp[i-c[j]]+1);
					}
					else
					{
						dp[i]=dp[i-c[j]]+1;
					}
				}
			}
			else if (i-c[j]==0)
			{
				dp[i]=1;
			}
		}
	}
	if (dp[x]==0)
	{
		cout<<-1;
		return 0;
	}
	cout<<dp[x];
	return 0;
}