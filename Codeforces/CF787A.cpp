#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b,c,d,n,ans=10101;
	cin>>a>>b;
	cin>>c>>d;
	n=max({a,b,c,d});
	for (int i=0;i<=n;++i)
	{
		for (int j=0;j<=n;++j)
		{
			if (b+(i*a)==d+(j*c))
			{
				ans=min(ans,b+(i*a));
			}
		}
	}
	if (ans==10101)
	{
		cout<<-1;
	}
	else
	{
		cout<<ans;
	}
	return 0;
}