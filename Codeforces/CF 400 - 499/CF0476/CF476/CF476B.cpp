#include <bits/stdc++.h>
#define ll long long
using namespace std;

int factorial(int n)
{
	int ans=1;
	for (int i=n;i>1;--i)
	{
		ans*=i;
	}
	return ans;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,plus1,minus1,plus2,minus2,total;
  float num,den,ans;
  string s1,s2;
  cin>>s1;
  cin>>s2;
  n=s1.length();
  plus1=0;
  plus2=0;
  minus1=0;
  minus2=0;
  total=0;
  for (int i=0;i<n;++i)
  {
  	if (s1[i]=='+')
  	{
  		++plus1;
  	}
  	else
  	{
  		++minus1;
  	}
  	if (s2[i]=='+')
  	{
  		++plus2;
  	}
  	else if (s2[i]=='-')
  	{
  		++minus2;
  	}
  	else
  	{
  		++total;
  	}
  }
  if (plus1<plus2||minus1<minus2)
  {
  	cout<<0;
  }
  else
  {
  	num=factorial(total);
  	den=factorial(plus1-plus2);
  	den*=factorial(minus1-minus2);
  	ans=num/den;
  	ans/=pow(2,total);
  	cout<<setprecision(10)<<ans;
  }
  return 0;
}