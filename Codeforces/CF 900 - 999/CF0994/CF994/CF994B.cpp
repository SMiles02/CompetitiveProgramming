#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,k,x,sum=0;
	cin>>n>>k;
	ll a[n];
	vector<pair<pair<ll,ll>,ll>> v;
	vector<ll> lowerPowerCoins;
	for (ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for (ll i=0;i<n;++i)
	{
		cin>>x;
		v.push_back(make_pair(make_pair(a[i],x),i));
	}
	sort(v.begin(),v.end());
	for (ll i=0;i<n;++i)
	{
		if (sz(lowerPowerCoins)>k)
		{
			sort(lowerPowerCoins.rbegin(),lowerPowerCoins.rend());
			sum-=lowerPowerCoins.back();
			lowerPowerCoins.pop_back();
		}
		a[v[i].second]=sum+v[i].first.second;
		sum+=v[i].first.second;
		lowerPowerCoins.push_back(v[i].first.second);
	}
	for (ll i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}