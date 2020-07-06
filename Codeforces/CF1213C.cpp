#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	ll k,n,m,ans;
	cin>>q;
	while (q--)
	{
		cin>>n>>m;
		if (m%10==0)
		{
			ans=0;
		}
		else if (m%10==5)
		{
			ans=(25)*(n/(m*10));
		}
		else if (m%2)
		{
			ans=(45)*(n/(m*10));
		}
		else
		{
			ans=(40)*(n/(m*10));
		}
		n%=(m*10);
		k=m;
		while (k<=n)
		{
			ans+=(k%10);
			k+=m;
		}
		cout<<ans<<"\n";
	}
	return 0;
}