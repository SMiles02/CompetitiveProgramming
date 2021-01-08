#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 3e5+7;
const ll INF = 1e18;
int n,m,k[mn],c[mn];

ll f(int x)
{
    ll ans=0;
    for (int i=1;i<=x;++i)
    {
        if (i>k[n-x+i])
            return INF+x;
        else
            ans+=c[i];
    }
    for (int i=n-x;i>=0;--i)
        ans+=c[k[i]];
    return ans;
}

void solve()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>k[i];
    for (int i=1;i<=m;++i)
        cin>>c[i];
    sort(k+1,k+n+1);
    int l=1,r=min(n,m),mid;
    if (f(l-1)<f(l))
    {
        cout<<f(l-1)<<"\n";
        return;
    }
    while (l<r)
    {
        mid=l+(r-l)/2+1;
        if (f(mid-1)<f(mid))
            r=mid-1;
        else
            l=mid;
    }
    cout<<f(l)<<"\n";
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