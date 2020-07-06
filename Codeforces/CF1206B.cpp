#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,a=1;
	ll ans=0;
	bool changeable=false;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>k;
		if (k>0)
		{
			ans+=(k-1);
		}
		else if (k<0)
		{
			ans+=((-1)-k);
			a*=(-1);
		}
		else
		{
			changeable=true;
			++ans;
		}
	}
	if (a==1||changeable)
	{
		cout<<ans;
	}
	else
	{
		cout<<ans+2;
	}
	return 0;
}