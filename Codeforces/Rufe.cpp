#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

ll n,m,a,b,k;

ll sumTo(ll x)
{
    return (x*(x+1))/2;
}

ll rectTravel(ll a, ll b, ll x)
{
    if (a==0||b==0)
        return 0;
    if (x>=a+b-2)
        return a*b;
    ll c,d;
    c=x-a;
    d=x-b;
    return (((x+1)*(x+2))/2)-sumTo(max(0,c+1))-sumTo(max(0,d+1));
}

ll topLeft(ll x)
{
    if (x==1)
        return 0;
    return rectTravel(a-1,b-1,x-2);
}

ll topRight(ll x)
{
    if (x==1)
        return 0;
    return rectTravel(a-1,m-b,x-2);
}

ll bottomLeft(ll x)
{
    if (x==1)
        return 0;
    return rectTravel(n-a,b-1,x-2);
}

ll bottomRight(ll x)
{
    if (x==1)
        return 0;
    return rectTravel(n-a,m-b,x-2);
}

ll check(ll x)
{
    return min(x,a-1)+min(x,b-1)+min(x,n-a)+min(x,m-b)+topLeft(x)+topRight(x)+bottomRight(x)+bottomLeft(x);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("rufe.in", "r", stdin);
    freopen("rufe.out", "w", stdout);
    cin>>n>>m>>a>>b>>k;
    ll l,r,mid,full=n;
    full*=m;
    l=1,r=1e18;
    if (k==(n*m)-1)
    {
        cout<<1;
        return 0;
    }
    while (l<r)
    {
        mid=l+(r-l)/2;
        if (full-1-check(mid)<=k)
            r=mid;
        else
            l=mid+1;
    }
    cout<<l;
    return 0;
}