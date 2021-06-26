#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,d=0;
	ll k,i,g;
	cin>>n;
	--n;
	cin>>k;
	g=k;
	for (i=0;i<n;++i)
	{
		cin>>k;
		g=gcd(g,k);
	}
	for (i=1;i*i<g;++i)
	{
		if (g%i==0)
		{
			++d;
		}
	}
	d*=2;
	if (i*i==g)
	{
		++d;
	}
	cout<<d;
	return 0;
}