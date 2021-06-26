#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,a,b,c,m,maxi;
  cin>>n>>a>>b>>c;
  m=min({a,b,c});
  int dp[n+1]={0};
  dp[0]=0;
  vector<int> v;
  for (int i=1;i<m;++i)
  {
  	dp[i]=-1;
  }
  for (int i=m;i<=n;++i)
  {
  	if (i-a>=0)
  	{
  		v.push_back(dp[i-a]);
  	}
  	if (i-b>=0)
  	{
  		v.push_back(dp[i-b]);
  	}
  	if (i-c>=0)
  	{
  		v.push_back(dp[i-c]);
  	}
  	maxi = *max_element(v.begin(), v.end());
  	if (maxi>-1)
  	{
  		dp[i] = maxi+1;
  	}
  	else
  	{
  		dp[i] = -1;
  	}
  	v.clear();
  }
  /**for (int i=0;i<n+1;++i)
  {
  	cout<<i<<": "<<dp[i]<<" ";
  }
  cout<<"\n";**/
  cout<<dp[n];
  return 0;
}