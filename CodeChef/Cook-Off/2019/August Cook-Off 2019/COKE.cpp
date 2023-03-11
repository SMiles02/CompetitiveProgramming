#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,c,t,m,k,l,r,d,p;
	cin>>t;
	while (t--)
	{
		cin>>n>>m>>k>>l>>r;
		c=51;
		while (n--)
		{
			cin>>d>>p;
			if (d>k)
			{
				d=max(k,d-m);
			}
			else
			{
				d=min(k,d+m);
			}
			if (d>=l&&r>=d)
			{
				c=min(c,p);
			}
		}
		if (c==51)
		{
			c=-1;
		}
		cout<<c<<"\n";
	}
	return 0;
}