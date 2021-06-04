#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5;
ll k,n,m;
int a[N];
ll mn[N], mx[N];

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

bool check(ll x)
{
    ll c = 0, d = 0;
    for (int i=0;i<k;++i)
    {
        mn[i]=(max(m*a[i]-x,0)+n-1)/n;
        mx[i]=(m*a[i]+x)/n;
        c+=mn[i];
        d+=mx[i];
    }
    if (c<=m&&m<=d)
        return 1;
    return 0;
}

void findArrangement(ll x)
{
    ll c = 0, t;
    for (int i=0;i<k;++i)
    {
        mn[i]=(max(m*a[i]-x,0)+n-1)/n;
        mx[i]=(m*a[i]+x)/n;
        c+=mn[i];
    }
    for (int i=0;i<k;++i)
    {
        t=min(mx[i]-mn[i],m-c);
        c+=t;
        cout<<mn[i]+t<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll l=0,r=1e18,mid;
    cin>>k>>n>>m;
    for (int i=0;i<k;++i)
        cin>>a[i];
    while (l<r)
    {
        mid=l+(r-l)/2;
        if (check(mid))
            r=mid;
        else
            l=mid+1;
    }
    findArrangement(l);
    return 0;
}