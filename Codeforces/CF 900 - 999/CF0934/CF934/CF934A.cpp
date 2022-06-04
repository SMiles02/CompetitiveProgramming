#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin>>n>>m;
	ll a[n],b[m],ans=1e18,cur;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for (int i=0;i<m;++i)
	{
		cin>>b[i];
	}
	for (int i=0;i<n;++i)
	{
		cur=-(1e18);
		for (int j=0;j<i;++j)
		{
			for (int k=0;k<m;++k)
			{
				cur=max(cur,a[j]*b[k]);
			}
		}
		for (int j=i+1;j<n;++j)
		{
			for (int k=0;k<m;++k)
			{
				cur=max(cur,a[j]*b[k]);
			}
		}
		ans=min(ans,cur);
	}
	cout<<ans;
	return 0;
}