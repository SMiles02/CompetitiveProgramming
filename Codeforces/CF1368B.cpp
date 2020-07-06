#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
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
    ll n,ans;
    cin>>n;
    string s="codeforces";
    int l=1,r=39,m;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (binpow(m,10)>n)
            r=m-1;
        else
            l=m;
    }
    ans=binpow(l,10);
    for (auto c : s)
    {
        if (ans<n)
        {
            ans/=l;
            ans*=(l+1);
            for (int i=0;i<=l;++i)
                cout<<c;
        }
        else
            for (int i=0;i<l;++i)
                cout<<c;
    }
    return 0;
}