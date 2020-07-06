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
	ll n,k,a,ans=0,mini=1e9;
	cin>>n>>k;
	int x[n],c[n];
	for (int i=0;i<n;++i)
	{
		cin>>x[i];
	}
	cin>>a;
	for (int i=0;i<n;++i)
	{
		cin>>c[i];
		if (c[i]<mini)
		{
			mini=c[i];
		}
		if (x[i]>k)
		{
			if ((x[i]-k)%a==0)
			{
				ans+=(((x[i]-k)/a)*mini);
			}
			else
			{
				ans+=((((x[i]-k)/a)+1)*mini);
			}
			k=x[i];
		}
	}
	cout<<ans;
	return 0;
}