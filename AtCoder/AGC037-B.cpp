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
	int n,rC=0,bC=0,gC=0,ans=0;
	string s;
	cin>>n;
	cin>>s;
	map<int,int> b;
	map<int,int> g;
	map<int,int> r;
	for (int i=0;i<(3*n);++i)
	{
		if (s[i]=='B')
		{
			b[bC]=i;
			++bC;
		}
		else if (s[i]=='G')
		{
			g[gC]=i;
			++gC;
		}
		else
		{
			r[rC]=i;
			++rC;
		}
	}
	for (int i=0;i<n;++i)
	{
		ans+=max({r[i],g[i],b[i]});
		ans-=min({r[i],g[i],b[i]});
	}
	cout<<ans;
	return 0;
}