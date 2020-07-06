#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n%i==0)
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
  cin>>n;
  if (n == 2)
  {
  	cout<<1;
  }
  else if (n%2==0)
  {
  	cout<<2;
  }
  else if (isPrime(n))
  {
  	cout<<1;
  }
  else if (isPrime(n-2))
  {
  	cout<<2;
  }
  else
  {
  	cout<<3;
  }
  return 0;
}