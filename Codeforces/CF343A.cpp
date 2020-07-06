#include <bits/stdc++.h>
#define ll long long
using namespace std;
//https://codeforces.com/contest/343/submission/52238061
ll resistor(ll a,ll b,ll ans)
{
	if (a==b)
	{
		return ans+1;
	}
	else if (a>b)
  	{
  		return resistor(a-b,b,ans+1);
  	}
  	else
  	{
  		return resistor(a,b-a,ans+1);
	}
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll a, b;
  cin>>a>>b;
  if (a>b)
  {
  	cout<<resistor(a-b,b,1);
  }
  else if (b>a)
  {
  	cout<<resistor(a,b-a,1);
  }
  else
  {
  	cout<<1;
  }
  return 0;
}