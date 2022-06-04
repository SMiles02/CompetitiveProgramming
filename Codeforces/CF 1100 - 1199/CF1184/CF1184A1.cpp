#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n,y;
  cin>>n;
  if (n % 2 == 1 && n > 4)
  {
  	y=n-3;
  	y/=2;
  	cout<<"1 "<<y;
  }
  else
  {
  	cout<<"NO";
  }
  return 0;
}