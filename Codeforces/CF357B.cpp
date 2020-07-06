#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,a,b,c;
	map<int,int> danced;
	cin>>n>>m;
	for (int i=0;i<m;++i)
	{
		cin>>a>>b>>c;
		if (danced[a])
		{
			if (danced[a]==1)
			{
				danced[b]=2;
				danced[c]=3;
			}
			else if (danced[a]==2)
			{
				danced[b]=1;
				danced[c]=3;
			}
			else
			{
				danced[b]=1;
				danced[c]=2;
			}
		}
		else if (danced[b])
		{
			if (danced[b]==1)
			{
				danced[a]=2;
				danced[c]=3;
			}
			else if (danced[b]==2)
			{
				danced[a]=1;
				danced[c]=3;
			}
			else
			{
				danced[a]=1;
				danced[c]=2;
			}
		}
		else if (danced[c])
		{
			if (danced[c]==1)
			{
				danced[b]=2;
				danced[a]=3;
			}
			else if (danced[c]==2)
			{
				danced[b]=1;
				danced[a]=3;
			}
			else
			{
				danced[b]=1;
				danced[a]=2;
			}
		}
		else
		{
			danced[a]=1;
			danced[b]=2;
			danced[c]=3;
		}
	}
	for (int i=1;i<=n;++i)
	{
		cout<<danced[i]<<" ";
	}
	return 0;
}