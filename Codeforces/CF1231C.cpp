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
	int n,m;
	ll sum=0;
	cin>>n>>m;
	int a[n][m];
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			cin>>a[i][j];
			sum+=a[i][j];
		}
	}
	for (int i=n-2;i>0;--i)
	{
		for (int j=m-2;j>0;--j)
		{
			if (!a[i][j])
			{
				a[i][j]=max(1,min(a[i+1][j],a[i][j+1]))-1;
				sum+=a[i][j];
			}
		}
	}
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m-1;++j)
		{
			if (a[i][j]>=a[i][j+1])
			{
				cout<<"-1";
				return 0;
			}
		}
	}
	for (int i=0;i<n-1;++i)
	{
		for (int j=0;j<m;++j)
		{
			if (a[i][j]>=a[i+1][j])
			{
				cout<<"-1";
				return 0;
			}
		}
	}
	cout<<sum;
	return 0;
}