#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,cur,k;
	cin>>n>>m;
	int rows[n], columns[m]={0}, nextColumns[m]={0};
	for (int i=0;i<n;++i)
	{
		cur=0;
		for (int j=0;j<m;++j)
		{
			cin>>k;
			cur+=k;
			columns[j]+=k;
		}
		rows[i]=(cur%2);
	}
	for (int i=0;i<n;++i)
	{
		cur=0;
		for (int j=0;j<m;++j)
		{
			cin>>k;
			cur+=k;
			nextColumns[j]+=k;
		}
		if (rows[i]!=(cur%2))
		{
			cout<<"No";
			return 0;
		}
	}
	for (int i=0;i<m;++i)
	{
		if ((columns[i]%2)!=(nextColumns[i]%2))
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}