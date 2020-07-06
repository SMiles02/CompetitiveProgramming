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
    cin>>n;
    vector<int> v;
    int p[n+1]={0};
    p[0]=1;
    p[1]=1;
    for (int i=2;i<n+1;++i)
    {
    	if (!p[i])
    	{
    		for (int j=2;j<=(n/i);++j)
    		{
    			p[i*j]=1;
    		}
    	}
    }
    for (int i=2;i<=n;++i)
    {
    	if (!p[i])
    	{
    		k=i;
    		while (k<=n)
    		{
    			v.push_back(k);
    			k*=i;
    		}
    	}
    }
    cout<<sz(v)<<"\n";
    for (int i=0;i<sz(v);++i)
    {
    	cout<<v[i]<<" ";
    }
    return 0;
}