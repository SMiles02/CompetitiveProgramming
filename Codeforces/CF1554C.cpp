//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
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

bool check(ll n, ll m, ll ans, int tr)
{
    return (((1LL<<tr)-1)^ans) > m;
}

void solve()
{
    ll n,m,ans=0;
    cin>>n>>m;
    for (int i=33;i>=0;--i)
    {
        //cout<<i<<": "<<check(n,m,ans,i)<<" "<<check(n,m,ans^(1LL<<i),i)<<"\n";
        if (n&(1LL<<i))
        {
            if (check(n,m,ans^(1LL<<i),i)||!check(n,m,ans,i))
                ans^=(1LL<<i);
        }
        else
        {
            if (check(n,m,ans,i)==0&&check(n,m,ans^(1LL<<i),i))
                ans^=(1LL<<i);
        }
        //cout<<i<<": "<<ans<<"\n";
    }
    cout<<(n^ans)<<"\n";
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