#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}
 
string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,k;
	cin>>n;
	vector<int> v;
	for (ll i=2;i*i<=n;++i)
	{
		if (n%i==0)
		{
			v.push_back(i);
			while (n%i==0)
			{
				n/=i;
			}
		}
	}
	k=v.size();
	for (int i=0;i<k;++i)
	{
		n*=v[i];
	}
	cout<<n;
	return 0;
}