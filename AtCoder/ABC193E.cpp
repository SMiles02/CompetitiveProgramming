#include <bits/stdc++.h>
#include <atcoder/all>
#define ll long long
using namespace std;

void solve()
{
    ll x,y,p,q,ans=LLONG_MAX;
    cin>>x>>y>>p>>q;
    pair<ll,ll> rv;
    for (int i=x;i<x+y;++i)
        for (int j=p;j<p+q;++j)
        {
            rv=atcoder::crt({i,j},{2*(x+y),p+q});
            if (rv.first==0&&rv.second==0)
                continue;
            if (rv.first==0)
                ans=min({ans,rv.second});
            else
                ans=min({ans,rv.first});
        }
    if (ans==LLONG_MAX)
        cout<<"infinity\n";
    else
        cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}