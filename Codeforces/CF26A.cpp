#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool primeFactors(int n)
{
	int factors, i;
	factors = 0;
	i = 2;	
	while (n > 1)
	{
		if (n%i==0)
		{
			while (n%i==0)
			{
				n/=i;
			}
			factors++;
		}
		i++;
	}
	if (factors==2)
	{
		return true;
	}
	return false;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,ans;
  cin>>n;
  ans=0;
  for (int i = 1; i <= n; i++)
  {
  	if (primeFactors(i))
  	{
  		ans++;
  	}
  }
  cout<<ans;
  return 0;
}