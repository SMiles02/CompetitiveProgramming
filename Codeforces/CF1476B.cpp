#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

const ll INF = 1e13;
int n,k,a[100];

bool ok(int x)
{
    ll s=a[0]+x;
    for (int i=1;i<n;++i)
    {
        if (100LL*a[i]>s*k)
            return 0;
        s+=a[i];
    }
    return 1;
}

void solve()
{
    cin>>n>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
    int l=0,r=INF,m;
    while (l^r)
    {
        m=l+(r-l)/2;
        if (ok(m))
            r=m;
        else
            l=m+1;
    }
    cout<<l<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}