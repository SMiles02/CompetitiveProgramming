//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
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

void solve()
{
    int n,l,r,ans,x;
    cin>>n>>l>>r;
    int a[n],b[n];
    b[0]=0;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    ans=a[0];
    x=a[0];
    for (int i=1;i<n;++i)
    {
        b[i]=b[i-1]+l;
        if (x<=b[i])
        {
            ans+=a[i];
            x=b[i]+a[i];
        }
        else
        {
            ans+=max(b[i]+a[i]-x,0LL);
            x=max(x,b[i]+a[i]);
        }
    }
    cout<<ans<<" ";
    sort(a,a+n);
    ans=a[0];
    x=a[0];
    for (int i=1;i<n;++i)
    {
        b[i]=b[i-1]+r;
        if (x<=b[i])
        {
            ans+=a[i];
            x=b[i]+a[i];
        }
        else
        {
            ans+=max(b[i]+a[i]-x,0LL);
            x=max(x,b[i]+a[i]);
        }
    }
    cout<<ans<<"\n";
}
  
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}