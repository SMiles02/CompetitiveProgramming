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

ll s(ll a)
{
    return a*a;
}

void solve()
{
    ll n,l=1,r=25000,m,x;
    cin>>n;
    if (n<5)
    {
        cout<<"0\n";
        return;
    }
    while (l^r)
    {
        m=l+(r-l)/2+1;
        x=2*m+1;
        //cout<<l<<" "<<r<<" "<<m<<"\n";
        //cout<<(s(x)+1)/2<<"\n";
        if ((s(x)+1)/2<=n)
            l=m;
        else
            r=m-1;
    }
    cout<<l<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    /**
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=i;j<=n;++j)
            for (int k=j;k<=n;++k)
                if (i*i+j*j==k*k&&i*i==j+k)
                    cout<<i<<" "<<j<<" "<<k<<"\n";
    **/
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}