#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,ans=1,k;
	cin>>n;
	for (int i=n;i>n-5;--i)
	{
		ans*=i;
	}
	k=ans;
	ans/=120;
	ans*=k;
	cout<<ans;
	return 0;
}