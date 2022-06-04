#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,k,a,b,ans;
  cin>>n>>m;
  ans=0;
  k = std::min(n,m/2);
  for (int i = 0; i <= k; i++)
  {
  	a=(n-i)/2;
  	b=m-2*i;
  	ans = std::max(std::min(a,b)+i, ans);
  }
  cout<<ans;
  return 0;
}