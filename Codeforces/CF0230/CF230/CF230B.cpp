#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPrime(int n)
{
	for (int j = 2; j * j <= n; j++)
	{
		if (n%j==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  ll x;
  cin>>n;
  for (int i = 0; i < n; i++)
  {
  	cin>>x;
  	if (x == 4)
  	{
  		cout<<"YES"<<"\n";
  	}
  	else if (x % 2 == 0)
  	{
  		cout<<"NO"<<"\n";
  	}
  	else if (x == 1)
  	{
  		cout<<"NO"<<"\n";
  	}
  	else if (sqrt(x) - floor(sqrt(x)) == 0)
  	{
  		if (isPrime(sqrt(x)))
  		{
  			cout<<"YES"<<"\n";
  		}
  		else
  		{
  			cout<<"NO"<<"\n";
  		}
  	}
  	else
  	{
  		cout<<"NO"<<"\n";
  	}
  }
  return 0;
}