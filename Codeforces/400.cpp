#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
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

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll s,k;
    cin>>s>>k;
    map<int,ll> m;
    m[k]=1;
    for (int i=k+1;i<=k+60;++i)
    {
        for (int j=max(i-k,k);j<i;++j)
            m[i]+=m[j];
        //cout<<i<<": "<<m[i]<<"\n";
    }
    vector<int> v;
    for (int i=k+60;i>=k;--i)
    {
        if (m[i]<=s&&m[i]>0)
        {
            s-=m[i];
            v.push_back(m[i]);
        }
    }
    v.push_back(0);
    //cout<<s<<"\n";
    cout<<sz(v)<<"\n";
    for (int i : v)
        cout<<i<<" ";
    return 0;
}