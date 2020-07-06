#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin>>n;
	if (n%4==1||n%4==2)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	if (n%2==0)
	{
		cout<<n/2<<"\n";
		for (int i=1;i<=(n/4);++i)
		{
			cout<<i<<" "<<n-i+1<<" ";
		}
		cout<<"\n"<<n/2<<"\n";
		for (int i=((n/4)+1);i<=(n/2);++i)
		{
			cout<<i<<" "<<n-i+1<<" ";
		}
		return 0;
	}
	vector<int> v;
	vector<int> w;
	ll m=(n)*(n+1)/4;
	for (int i=n;i>0;--i)
	{
		if (m>=i)
		{
			m-=i;
			v.push_back(i);
		}
		else
		{
			w.push_back(i);
		}
	}
	cout<<v.size()<<"\n";
	for (auto j:v)
	{
		cout<<j<<" ";
	}
	cout<<"\n"<<w.size()<<"\n";
	for (auto k:w)
	{
		cout<<k<<" ";
	}

	return 0;
}