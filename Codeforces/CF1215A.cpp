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
	int a1,a2,k1,k2,n,b,ans;
	cin>>a1;
	cin>>a2;
	cin>>k1;
	cin>>k2;
	cin>>n;
	b=a1*(k1-1);
	b+=(a2*(k2-1));
	cout<<max(0,n-b)<<" ";
	if (k1>k2)
	{
		if (n<(k2*a2))
		{
			cout<<(n/k2);
			return 0;
		}
		ans=a2;
		n-=(k2*a2);
		cout<<ans+(n/k1);
	}
	else
	{
		if (n<(k1*a1))
		{
			cout<<(n/k1);
			return 0;
		}
		ans=a1;
		n-=(k1*a1);
		cout<<ans+(n/k2);
	}
	return 0;
}