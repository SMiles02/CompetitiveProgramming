#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,k,mini,i;
  cin>>n>>m;
  int c[n] = {0};
  mini=1001;
  for (i=0;i<m;i++)
  {
  	cin>>k;
  	++c[k-1];
  }
  for (i=0;i<n;++i)
  {
  	mini=min(mini,c[i]);
  }
  cout<<mini;
  return 0;
}