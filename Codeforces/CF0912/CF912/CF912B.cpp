#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,k,ans=1;
	cin>>n>>k;
	if (k==1)
	{
		cout<<n;
		return 0;
	}
	while (ans<n)
	{
		ans*=2;
		++ans;
	}
	cout<<ans;
	return 0;
}