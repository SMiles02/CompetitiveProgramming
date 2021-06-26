#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n,k,x;
  std::vector<ll> v;
  cin>>n>>k;
  for (ll i = 1; i*i <= n; i++)
  {
  	if (n%i==0)
  	{
  		v.push_back(i);
  	}
  }
  x=v.size();
  if (x>=k)
  {
  	cout<<v[k-1];
  }
  else if (v[x-1] * v[x-1] == n)
  {
  	if (k > 2*x-1)
  	{
  		cout<<-1;
  	}
  	else
  	{
  		cout<<n/(v[2*x-1-k]);
  	}
  }
  else if (k>2*x)
  {
  	cout<<-1;
  }
  else
  {
  	cout<<n/(v[2*x-k]);
  }
  return 0;
}