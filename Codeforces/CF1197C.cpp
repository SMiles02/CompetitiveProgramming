#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,k;
  ll ans;
  cin>>n>>k;
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
  for (int i=n-k-1;i>-1;--i)
  {
  	ans+=dp[i];
  }
  cout<<ans;
  return 0;
}