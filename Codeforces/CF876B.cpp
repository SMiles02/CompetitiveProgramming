#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,m,f;
	cin>>n>>k>>m;
	map<int,vector<int>> key;
	while (n--)
	{
		cin>>f;
		key[f%m].push_back(f);
	}
	for (int i=0;i<m;++i)
	{
		if (sz(key[i])>=k)
		{
			cout<<"Yes\n";
			for (int j=0;j<k;++j)
			{
				cout<<key[i][j]<<" ";
			}
			return 0;
		}
	}
	cout<<"No";
	return 0;
}