#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,ans;
  string a,b;
  cin>>n;
  cin>>a;
  cin>>b;
  ans=0;
  for (int i=0;i<n;++i)
  {
  	ans+=min(abs(a[i]-b[i]),10-abs(a[i]-b[i]));
  }
  cout<<ans;
  return 0;
}