#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool factorsOf(int n)
{
	for (int i=317;i*i<=n;++i)
	{
		if (n%i==0)
		{
			if (n/i>316&&n/i<1000)
			{
				cout<<i<<"\n";
				return true;
			}
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int a=9;a>2;--a)
	{
		for (int b=9;b>=0;--b)
		{
			for (int c=9;c>=0;--c)
			{
				if (factorsOf(a*100001+b*10010+c*1100))
				{
					cout<<a*100001+b*10010+c*1100;
					return 0;
				}
			}
		}
	}
	return 0;
}