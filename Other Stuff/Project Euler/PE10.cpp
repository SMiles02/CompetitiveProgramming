#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll primeCount;
	primeCount=0;
	ll a[2000001]={0};
	for (int i=2;i<2000001;++i)
	{
		if (a[i]==0)
		{
			primeCount+=i;
			for (int j=2;i*j<2000001;++j)
			{
				a[i*j]=-1;
			}
		}
	}
	cout<<primeCount;
	cout<<"didnt reach, primecount="<<primeCount;
	return 0;
}