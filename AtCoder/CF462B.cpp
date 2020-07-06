#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,k,m=0,ans=0;
	string s,alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cin>>n>>k;
	cin>>s;
	vector<ll> v;
	map<char,int> occurences;
	for (int i=0;i<n;++i)
	{
		++occurences[s[i]];
	}
	for (int i=0;i<26;++i)
	{
		v.push_back(occurences[alpha[i]]);
		//cout<<occurences[alpha[i]]<<"\n";
		++m;
	}
	sort(v.rbegin(),v.rend());
	for (int i=0;i<m;++i)
	{
		if (v[i]<=k)
		{
			ans+=(v[i]*v[i]);
			//cout<<v[i]<<", newN = "<<n-v[i]<<"\n";
			k-=v[i];
		}
		else
		{
			ans+=(k*k);
			//cout<<k<<", newN = "<<0<<"\n";
			k=0;
		}
	}
	//cout<<"\n";
	cout<<ans;
	return 0;
}