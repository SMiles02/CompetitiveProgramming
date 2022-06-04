#include <bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,ans,g,maxi;
	cin>>n;
	int a[n];
	int b[n];
	map<pair<int,int>,int> possibleD;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for (int i=0;i<n;++i)
	{
		cin>>b[i];
	}
	ans=0;
	maxi=0;
	for (int i=0;i<n;++i)
	{
		if (a[i]==0)
		{
			if (b[i]==0)
			{
				++ans;
			}
		}
		else
		{
			if ((a[i]>0&&b[i]>0))
			{
				g=gcd(a[i],b[i]);
				a[i]/=g;
				b[i]/=g;
			}
			else if (a[i]<0&&b[i]<0)
			{
				a[i]*=-1;
				b[i]*=-1;
				g=gcd(a[i],b[i]);
				a[i]/=g;
				b[i]/=g;
			}
			else if (b[i]==0)
			{
				a[i]=0;
			}
			else
			{
				if (b[i]>0)
				{
					b[i]*=-1;
					a[i]*=-1;
				}
				g=gcd(a[i],-b[i]);
				a[i]/=g;
				b[i]/=g;
			}
			pair<int, int> p = make_pair(a[i],b[i]);
			++possibleD[p];
			maxi=max(maxi,possibleD[p]);
		}
	}
	cout<<maxi+ans;
	return 0;
}