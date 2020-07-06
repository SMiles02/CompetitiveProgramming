#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,ans=0;
	cin>>n;
	ll a[n];
	cin>>a[0];
	for (int i=1;i<n;++i)
	{
		cin>>a[i];
		if (a[i]<a[i-1])
		{
			ans+=a[i-1]-a[i];
			a[i]=a[i-1];
		}
	}
	cout<<ans;
	return 0;
}