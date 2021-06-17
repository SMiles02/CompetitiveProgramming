#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
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

void solve()
{
    ll x,y,z,a,b,l=0,r,m,ans;
    cin>>x>>y>>a>>b;
    if (x>y)
        swap(x,y);
    if (a>b)
        swap(a,b);
    r=min(x/a,y/b);
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (y-m*b>=x-m*a)
            l=m;
        else
            r=m-1;
    }
    ans=l;
    y-=l*b;
    x-=l*a;
    //cout<<x<<" "<<y<<" "<<ans<<"\n";
    z=x/(a+b);
    ans+=z*2;
    x-=(a+b)*z;
    y-=(a+b)*z;
    if (a<=x&&b<=y)
        ++ans;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}