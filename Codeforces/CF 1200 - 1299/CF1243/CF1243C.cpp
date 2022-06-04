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
    ll n,m,k;
    cin>>m;
    n=m;
    vector<ll> v;
    k=sqrt(n);
    for (int i=2;i<=k;++i)
    {
        if (n%i==0)
        {
            while (n%i==0)
            {
                n/=i;
            }
            v.push_back(i);
            k=sqrt(n);
        }
    }
    if (n>1&&n!=m)
    {
        v.push_back(n);
    }
    if (sz(v)==0)
    {
        cout<<m;
        return 0;
    }
    if (sz(v)==1)
    {
        cout<<v[0];
    }
    else
    {
        cout<<1;
    }
    return 0;
}