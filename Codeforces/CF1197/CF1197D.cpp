#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,k;
  ll ans,cur;
  cin>>n>>m>>k;
  int a[n+1];
  ll dp[n+1];
  dp[0]=0;
  for (int i=1;i<=n;++i)
  {
  	cin>>a[i];
  	dp[i]=dp[i-1]+a[i];
  }
  //sum(a[l] to a[r]) = dp[r]-dp[l-1]
  ans=0;
  for (int i=1;i<=n;++i)
  {
  	
  }
  cout<<ans;
  return 0;
}