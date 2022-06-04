#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
  ll a[n], k, m;
  for (int i = 0; i < n; i++)
  {
  	cin>>a[i];
  }
  k=a[0];
  while (k%2==0)
  {
  	k/=2;
  }
  while (k%3==0)
  {
  	k/=3;
  }
  for (int i = 1; i < n; i++)
  {
  	m = a[i];
  	while (m%2==0)
  	{
  		m/=2;
  	}
  	while (m%3==0)
  	{
  		m/=3;
  	}
  	if (m!=k)
  	{
  		cout<<"No";
  		return 0;
  	}
  }
  cout<<"Yes";
  return 0;
}