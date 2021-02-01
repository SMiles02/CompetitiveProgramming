#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll primeCount;
	primeCount=0;
	ll a[500000]={0};
	for (int i=2;i<500000;++i)
	{
		if (a[i]==0)
		{
			++primeCount;
			if (primeCount==10001)
			{
				cout<<i;
				return 0;
			}
			for (int j=2;i*j<500000;++j)
			{
				a[i*j]=-1;
			}
		}
	}
	cout<<"didnt reach, primecount="<<primeCount;
	return 0;
}