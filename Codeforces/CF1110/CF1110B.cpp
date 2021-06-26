#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,k;
  ll ans;
  cin>>n>>m>>k;
  int a[n];
  int dp[n-1];
  cin>>a[0];
  for (int i=1;i<n;++i)
  {
  	cin>>a[i];
  	dp[i-1]=a[i]-a[i-1];
  }
  sort(dp,dp+(n-1));
  ans=0;
  for (int i=n-1-k;i>-1;--i)
  {
  	ans+=dp[i]+1;
  }
  cout<<ans;
  return 0;
}