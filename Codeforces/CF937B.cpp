#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int minFactor(int k)
{
	if (k%2==0)
	{
		return 2;
	}
	for (int i=3;i<=sqrt(k);++i)
	{
		if (k%i==0)
		{
			return i;
		}
	}
	return k;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int p,y;
	cin>>p>>y;
	for (int j=y;j>=max(y-300,p+1);--j)
	{
		if (minFactor(j)>p)
		{
			cout<<j;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}