#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const ll INF = 1e18;
ll c[7],x,y;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

ll f(ll k)
{
    ll ans,n,m;
    if (k>=0)
        ans=k*c[1];
    else
        ans=(-k)*c[4];
    n=x-k;
    m=y-k;
    if (n>=0)
        ans+=n*c[6];
    else
        ans+=(-n)*c[3];
    if (m>=0)
        ans+=m*c[2];
    else
        ans+=(-m)*c[5];
    return ans;
}

void solve()
{
    cin>>x>>y;
    for (int i=1;i<7;++i)
        cin>>c[i];
    int l=-1000000000+1,r=1000000000,m;
    if (f(l-1)<f(l))
    {
        cout<<f(l-1)<<"\n";
        return;
    }
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (f(m-1)<f(m))
            r=m-1;
        else
            l=m;
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