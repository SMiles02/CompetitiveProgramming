#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int x,y,l=0,r,m,d,v;
    cin>>x>>y;
    r=min(y,31623);
    while (l^r)
    {
        m=l+(r-l)/2+1;
        if ((m+1)*(m-1)<=x)
            l=m;
        else
            r=m-1;
    }
    ll ans=(l*(l-1))/2;
    d=l;
    while (d<y)
    {
        l=d+1;r=y;
        v=x/(l+1);
        while (l<r)
        {
            m=l+(r-l)/2+1;
            if (x/(m+1)==v)
                l=m;
            else
                r=m-1;
        }
        ans+=1LL*(r-d)*v;
        d=l;
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