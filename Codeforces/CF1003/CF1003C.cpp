#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	double curAns,maxAns=0;
	cin>>n>>k;
	int a[n];
	int dp[n+1];
	dp[0]=0;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		dp[i+1]=dp[i]+a[i];
		//cout<<"dp["<<i+1<<"] = "<<dp[i+1]<<"\n";
	}
	for (int i=1;i<n-k+2;++i)
	{
		for (int j=i+k-1;j<=n;++j)
		{
			curAns=(dp[j]-dp[i-1]);
			curAns/=(j-i+1);
			//cout<<i<<" to "<<j<<" is equal to "<<curAns<<"\n";
			maxAns=max(maxAns,curAns);
		}
	}
	cout<<setprecision(11)<<maxAns;
	return 0;
}