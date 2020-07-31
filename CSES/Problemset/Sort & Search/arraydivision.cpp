#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k;
int a[200000];

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

bool check(ll x)
{
    ll cur=0,ans=1;
    for (int i=0;i<n;++i)
    {
        cur+=a[i];
        if (cur>x)
        {
            ++ans;
            cur=a[i];
        }
    }
    if (ans>k)
        return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    ll l=1,r=2e14,m;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        l=max(l,a[i]);
    }
    while (l<r)
    {
        m=l+(r-l)/2;
        if (check(m))
            r=m;
        else
            l=m+1;
    }
    cout<<l;
    return 0;
}