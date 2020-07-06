#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int v1,v2,t,d,ans;
	cin>>v1>>v2;
	cin>>t>>d;
	int a[t];
	a[0]=v1;
	for (int i=1;i<t;++i)
	{
		a[i]=a[i-1]+d;
	}
	a[t-1]=v2;
	ans=v2;
	for (int i=t-2;i>-1;--i)
	{
		a[i]=min(a[i],a[i+1]+d);
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}