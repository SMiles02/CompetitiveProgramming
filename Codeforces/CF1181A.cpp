#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll x,y,z,ans;
  cin>>x>>y>>z;
  ans=(x+y)/z;
  x%=z;
  y%=z;
  if (x+y>=z)
  {
  	if (x>=y)
  	{
  		cout<<ans<<" "<<(z-x);
  	}
  	else
  	{
  		cout<<ans<<" "<<(z-y);
  	}
  }
  else
  {
  	cout<<ans<<" "<<0;
  }
  return 0;
}