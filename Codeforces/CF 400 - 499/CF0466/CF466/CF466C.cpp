#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
  int a[n];
  ll dp[n+1];
  dp[0]=0;
  for (int i=0;i<n;++i)
  {
  	cin>>a[i];
  	dp[i+1]=dp[i]+a[i];
  	//cout<<dp[i+1]<<"\n";
  }
  if (dp[n]%3==0)
  {
  	int oneCount;
  	ll ans,one,two;
  	one=dp[n]/3;
  	two=2*one;
  	ans=0;
  	oneCount=0;
  	for (int i=1; i < n; ++i)
  	{
  		if (dp[i]==two)
  		{
  			//cout<<"test";
  			ans+=oneCount;
  		}
  		if (dp[i]==one)
  		{
  			++oneCount;
  		}
  		//cout<<"OneCount after " << i << " is "<<oneCount<<"\n";
  	}
  	cout<<ans;
  }
  else
  {
  	cout<<0;
  }
  return 0;
}