#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int gcd(int a,int b)
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
	int n,k,g,maxi;
	ll ans=0,cur;
	cin>>n;
	int a[n];
	vector<int> v;
	map<int,int> m;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		if (!m[a[i]])
		{
			v.push_back(a[i]);
		}
		++m[a[i]];
	}
	k=v.size();
	sort(v.begin(), v.end());
	g=v[1]-v[0];
	for (int i=1;i<k-1;++i)
	{
		g=gcd(g,v[i+1]-v[i]);
	}
	maxi=v[k-1];
	for (int i=0;i<k-1;++i)
	{
		cur=((maxi-v[i])/g);
		cur*=m[v[i]];
		ans+=cur;
	}
	cout<<ans<<" "<<g;
	return 0;
}