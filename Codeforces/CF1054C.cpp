#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,cur;
	cin>>n;
	int a[n];
	int b[n];
	int d[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for (int i=0;i<n;++i)
	{
		cin>>b[i];
		d[i]=n-a[i]-b[i];
		if (d[i]<1)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	for (int i=0;i<n;++i)
	{
		cur=0;
		for (int j=i+1;j<n;++j)
		{
			if (d[j]>d[i])
			{
				++cur;
			}
		}
		if (cur!=b[i])
		{
			cout<<"NO";
			return 0;
		}
		cur=0;
		for (int j=i-1;j>-1;--j)
		{
			if (d[j]>d[i])
			{
				++cur;
			}
		}
		if (cur!=a[i])
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES\n";
	for (int i=0;i<n;++i)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}