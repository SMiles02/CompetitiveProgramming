#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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
    int n,k,z,ans=0;
    cin>>n>>k>>z;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    int p[n];
    p[0]=a[0];
    for (int i=1;i<n;++i)
        p[i]=p[i-1]+a[i];
    int m[n];
    m[0]=0;
    for (int i=1;i<n;++i)
        m[i]=max(m[i-1],a[i]+a[i-1]);
    for (int i=1;i<=k;++i)
    {
        if ((i&1)!=(k&1))
            for (int j=0;j<z&&i+2*j+1<=k;++j)
            {
                //cout<<i<<" "<<j<<" "<<p[i]+m[i]*j+a[i-1]<<"\n";
                ans=max(ans,p[i]+m[i]*j+a[i-1]);
            }
        else
            for (int j=0;j<=z&&i+2*j<=k;++j)
            {
                //cout<<i<<" "<<j<<" "<<p[i]+m[i]*j<<"\n";
                ans=max(ans,p[i]+m[i]*j);
            }
    }
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