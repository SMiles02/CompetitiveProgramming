#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t,n,maxi,k;
	cin>>t;
	vector<int> a;
	for (int i=0;i<t;++i)
	{
		cin>>n;
		for (int j=0;j<n;++j)
		{
			//cout<<"i: "<<i<<", j: "<<j<<"\n";
			cin>>k;
			a.push_back(k);
		}
		maxi=0;
		for (int j=0;j<n;++j)
		{
			cin>>k;
			maxi=max(maxi,20*a[j]-(10*k));
		}
		cout<<maxi<<"\n";
		a.clear();
	}
	return 0;
}