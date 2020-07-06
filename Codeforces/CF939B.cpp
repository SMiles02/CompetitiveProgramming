#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,k,a,b,c,x;
	cin>>n>>k;
	c=n+1;
	for (int i=0;i<k;++i)
	{
		cin>>x;
		if (n%x<c)
		{
			a=i+1;
			b=n/x;
			c=n%x;
		}
	}
	cout<<a<<" "<<b;
	return 0;
}