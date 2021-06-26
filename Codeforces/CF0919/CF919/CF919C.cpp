#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	string s[n];
	int dp[m+1];
	for (int i=0;i<n;++i)
	{
		cin>>s[i];
		dp[0]=0;
		for (int j=0;j<m;++j)
		{
			dp[j+1]=dp[j]+(s[i][j]=='*');
		}
		for (int j=0;j<m-k+1;++j)
		{
			if (dp[j+k]-dp[j]==0)
			{
				++ans;
			}
		}
	}
	int dp2[n+1];
	for (int j=0;j<m;++j)
	{
		dp2[0]=0;
		for (int i=0;i<n;++i)
		{
			dp2[i+1]=dp2[i]+(s[i][j]=='*');
		}
		for (int i=0;i<n-k+1;++i)
		{
			if (dp2[i+k]-dp2[i]==0)
			{
				++ans;
			}
		}
	}
	if (k==1)
	{
		ans/=2;
	}
	cout<<ans;
	return 0;
}