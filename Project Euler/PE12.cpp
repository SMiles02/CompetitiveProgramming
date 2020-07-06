#include <bits/stdc++.h>
#define ll long long
using namespace std;

int numOfFactors(int n)
{
	int factors=2;
	for (int i=2;i*2<=n;++i)
	{
		if (n%i==0)
		{
			++factors;
		}
	}
	return factors;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b;
	a=2;
	for (ll i=11;i<1000000;++i)
	{
	    b=numOfFactors(i+1);
		if (pow(2,a+b)>501)
		{
			cout<<"test\n";
			i*=(i+1);
			i/=2;
			cout<<i;
			return 0;
		}
		a=b;
	}
	return 0;
}