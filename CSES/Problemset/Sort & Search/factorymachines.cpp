#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll n,t,l=1,r=1,m,k=1e9;
int a[200000];

ll check()
{
    ll ans=0;
    for (int i=0;i<n;++i)
        ans+=(m/a[i]);
    return ans;
}

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>t;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (r=1;r<=1e18;r*=10)
    {
        m=r;
        if (check()>=t)
            break;
    }
    while (l<r)
    {
        m=l+(r-l)/2;
        if (check()<t)
            l=m+1;
        else
            r=m;
    }
    cout<<l;
    return 0;
}