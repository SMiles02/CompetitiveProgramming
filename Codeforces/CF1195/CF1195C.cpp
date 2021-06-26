#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int a[n][2];
	for (int i=0;i<n;++i)
	{
		cin>>a[i][0];
	}
	for (int i=0;i<n;++i)
	{
		cin>>a[i][1];
	}
	if (n==1)
	{
		cout<<max(a[0][0],a[0][1]);
		return 0;
	}
	if (n==2)
	{
		cout<<max(a[0][0]+a[1][1],a[0][1]+a[1][0]);
		return 0;
	}
	ll dp[n][3];
	dp[0][0]=a[0][0];
	dp[0][1]=a[0][1];
	dp[1][0]=dp[0][1]+a[1][0];
	dp[1][1]=dp[0][0]+a[1][1];
	dp[1][2]=max(dp[0][0],dp[0][1]);
	for (int i=2;i<n;++i)
	{
		dp[i][0]=max(dp[i-1][1]+a[i][0],dp[i-1][2]+a[i][0]);
		dp[i][1]=max(dp[i-1][0]+a[i][1],dp[i-1][2]+a[i][1]);
		dp[i][2]=max(dp[i-1][0],dp[i-1][1]);
	}
	cout<<max(dp[n-1][0],dp[n-1][1]);
	return 0;
}