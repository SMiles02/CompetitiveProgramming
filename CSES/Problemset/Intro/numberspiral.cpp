#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t,x,y;
	cin>>t;
	while (t--)
	{
		cin>>x>>y;
		if (x==y)
		{
			cout<<(x-1)*(x-1)+x<<"\n";
		}
		else if (x<y)
		{
			if (y%2)
			{
				cout<<(y*y)+1-x<<"\n";
			}
			else
			{
				cout<<(y-1)*(y-1)+x<<"\n";
			}
		}
		else
		{
			if (x%2)
			{
				cout<<(x-1)*(x-1)+y<<"\n";
			}
			else
			{
				cout<<(x*x)+1-y<<"\n";
			}
		}
	}
	return 0;
}