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
	int n,k;
	ll ans=0,b;
	cin>>n;
	vector<int> v;
	v.push_back(-1);
	for (int i=0;i<n;++i)
	{
		cin>>k;
		if (k<0)
		{
			v.push_back(i);
		}
	}
	k=v.size();
	v.push_back(n);
	cout<<"k="<<k<<"\n";
	for (int i=0;i<=k;++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n";
	for (int i=1;i<k;++i)
	{
		for (int j=i;j<k;j+=2)
		{
			ans+=((v[j+1]-v[j])*(v[i]-v[i-1]));
		}
	}
	b=n;
	b*=(b+1);
	b/=2;
	cout<<b-ans<<" "<<ans;
	return 0;
}