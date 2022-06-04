#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t,n,ans,mini,k;
	cin>>t;
	vector<int> v;
	while (t--)
	{
		cin>>n;
		ans=0;
		for (int i=0;i<n;++i)
		{
			cin>>k;
			v.push_back(k);
		}
		mini=v[n-1];
		for (int i=n-2;i>-1;--i)
		{
			if (mini<v[i])
			{
				++ans;
			}
			mini=min(mini,v[i]);
		}
		v.clear();
		cout<<ans<<"\n";
	}
	return 0;
}