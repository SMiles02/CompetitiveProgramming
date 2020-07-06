#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,ans=0,maxAdds=0,curAdds;
	cin>>n>>k;
	int a[n],t[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for (int i=0;i<n;++i)
	{
		cin>>t[i];
		if (t[i])
		{
			ans+=a[i];
		}
	}
	for (int i=0;i<k;++i)
	{
		maxAdds+=(1-t[i])*a[i];
	}
	curAdds=maxAdds;
	for (int i=1;i<n-k+1;++i)
	{
		curAdds-=(1-t[i-1])*a[i-1];
		curAdds+=(1-t[i+k-1])*a[i+k-1];
		maxAdds=max(maxAdds,curAdds);
	}
	cout<<maxAdds+ans;
	return 0;
}