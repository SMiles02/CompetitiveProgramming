#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,su=0,cur=0,x,y;
	cin>>n;
	int a[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		su+=a[i];
	}
	cin>>x>>y;
	for (int i=0;i<n-1;++i)
	{
		cur+=a[i];
		if (x<=cur&&y>=cur&&x<=(su-cur)&&y>=(su-cur))
		{
			cout<<i+2;
			return 0;
		}
	}
	cout<<0;
	return 0;
}