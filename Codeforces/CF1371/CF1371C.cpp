#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

bool rec(ll a, ll b, ll n, ll m)
{
    ll x;
    if ((!n)&&(!m))
    {
        if (a>-1&&b>-1)
            return 1;
        return 0;
    }
    if (a==b)
    {
        if (!m)
            return 1;
        if (!n)
        {
            if (a>=m)
                return 1;
            return 0;
        }
        if (a<min(n,m))
            return 0;
        return rec(a-min(n,m),b-min(n,m),n-min(n,m),m-min(n,m));
    }
    if (a>b)
    {
        if (!n)
        {
            if (b>=m)
                return 1;
            return 0;
        }
        if (!m)
            return 1;
        x=min(a-b,n);
        return rec(a-x,b,n-x,m);
    }
    if (!n)
    {
        if (m>a)
            return 0;
        return 1;
    }
    if (!m)
        return 1;
    x=min(b-a,n);
    return rec(a,b-x,n-x,m);
}

void solve()
{
    ll a,b,n,m;
    cin>>a>>b>>n>>m;
    if (a+b<n+m)
        cout<<"No\n";
    else if (rec(a,b,n,m))
        cout<<"Yes\n";
    else
        cout<<"No\n";
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