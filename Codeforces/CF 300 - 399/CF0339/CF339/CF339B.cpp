#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k,cur=1;
	ll ans=0;
	cin>>n>>m;
	while (m--)
	{
		cin>>k;
		if (k>=cur)
		{
			ans+=k-cur;
		}
		else
		{
			ans+=k+n-cur;
		}
		cur=k;
	}
	cout<<ans;
	return 0;
}