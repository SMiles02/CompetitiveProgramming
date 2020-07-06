#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,q,t,r,c,x;
	cin>>n>>m>>q;
	int a[n][m];
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			a[i][j]=0;
		}
	}
	vector<vector<int>> v;
	for (int i=0;i<q;++i)
	{
		cin>>t;
		if (t==3)
		{
			cin>>r>>c>>x;
			v.push_back({t,r-1,c-1,x});
		}
		else
		{
			cin>>r;
			v.push_back({t,r-1});
		}
	}
	for (int i=q-1;i>-1;--i)
	{
		if (v[i][0]==3)
		{
			a[v[i][1]][v[i][2]]=v[i][3];
		}
		else if (v[i][0]==2)
		{
			for (int j=n-1;j>0;--j)
			{
				swap(a[j][v[i][1]],a[j-1][v[i][1]]);
			}
		}
		else
		{
			for (int j=m-1;j>0;--j)
			{
				swap(a[v[i][1]][j],a[v[i][1]][j-1]);
			}
		}
	}
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}