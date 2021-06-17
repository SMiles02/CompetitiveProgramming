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
    int n,q,k,l,r,m;
    cin>>n>>q;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    while (q--)
    {
        cin>>k;
        if (a[n-1]-n<k)
        {
            cout<<k+n<<"\n";
            continue;
        }
        l=0;r=n-1;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (k<=a[m]-m-1)
                r=m;
            else
                l=m+1;
        }
        if (l==0)
            cout<<k<<"\n";
        else
            cout<<k+l<<"\n";
    }
    return 0;
}