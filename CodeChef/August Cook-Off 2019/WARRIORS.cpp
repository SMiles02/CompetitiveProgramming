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
	int t,n,q,k,i;
	ll x;
	cin>>t;
	vector<int> p;
	while (t--)
	{
		cin>>n>>q;
		for (i=0;i<n;++i)
		{
			cin>>k;
			p.push_back(k);
		}
		sort(p.begin(), p.end());
		while (q--)
		{
			cin>>x;
			for (i=0;i<n;++i)
			{
				if (x>p[i])
				{
					x-=p[i];
					x*=2;
				}
				else
				{
					break;
				}
			}
			cout<<i<<"\n";
		}
		p.clear();
	}
	return 0;
}