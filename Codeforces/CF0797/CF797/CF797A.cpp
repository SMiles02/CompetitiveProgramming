#include <bits/stdc++.h>
#define ll long long
using namespace std;

std::vector<int> primeFactorisation(int num)
{
	std::vector<int> primes;
	for (int div=2; div*div<=num; div++)
	{
		while (div*div<=num && num%div==0)
		{
			primes.push_back(div);
			num/=div;
		}
	}
	if (num>1)
	{
		primes.push_back(num);
	}
	return primes;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,k,len,c;
  cin>>n>>k;
  std::vector<int> v = primeFactorisation(n);
  std::vector<int> ans;
  len=v.size();
  if (k>len)
  {
  	cout<<-1;
  }
  else if (k==len)
  {
  	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
  }
  else
  {
  	for (int i = 0; i<k-1; i++)
  	{
  		ans.push_back(v[i]);
  	}
  	c=v[k-1];
  	for (int i=k; i<len;i++)
  	{
  		c*=v[i];
  	}
  	ans.push_back(c);
  	std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
  }
  return 0;
}