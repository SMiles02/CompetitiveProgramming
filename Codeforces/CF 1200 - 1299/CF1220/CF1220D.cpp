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
    int n,ones=0,zeroes=0;
    ll g,k;
    cin>>n;
    if (n==1)
    {
    	cout<<0;
    	return 0;
    }
    vector<ll> v;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (k%2)
        {
            ++ones;
        }
        else
        {
            ++zeroes;
        }
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    g=(v[1]-v[0]);
    for (int i=1;i<n-1;++i)
    {
    	g=gcd(g,v[i+1]-v[i]);
    }
    //cout<<g<<" "<<ones<<" "<<zeroes<<"\n";
    if (g==1)
    {
    	if (ones<zeroes)
    	{
    		cout<<ones<<"\n";
    		for (int i=0;i<n;++i)
    		{
    			if (v[i]%2)
    			{
    				cout<<v[i]<<"\n";
    			}
    		}
    	}
    	else
    	{
    		cout<<zeroes<<"\n";
	    	for (int i=0;i<n;++i)
	    	{
	    		if (!(v[i]%2))
	    		{
	    			cout<<v[i]<<"\n";
	    		}
	    	}
	    }
    }
    else
    {
    	cout<<0;
    }
    return 0;
}