#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,x,q,m;
	cin>>n;
	map<int,int> numberOfShops;
	while (n--)
	{
		cin>>x;
		++numberOfShops[x];
	}
	for (int i=2;i<100001;++i)
	{
		numberOfShops[i]+=numberOfShops[i-1];
	}
	cin>>q;
	while (q--)
	{
		cin>>m;
		cout<<numberOfShops[min(m,100000)]<<"\n";
	}
	return 0;
}