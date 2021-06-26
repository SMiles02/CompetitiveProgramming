#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,k=1,ans=0;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		k*=2;
		ans+=k;
	}
	cout<<ans;
	return 0;
}