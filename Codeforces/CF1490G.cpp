#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

const int INF = 1e9;

void solve()
{
    int n,m,x,l,r,mid,c;
    cin>>n>>m;
    ll p[n],mp[n];
    cin>>p[0];
    mp[0]=p[0];
    for (int i=1;i<n;++i)
    {
        cin>>p[i];
        p[i]+=p[i-1];
        mp[i]=max(mp[i-1],p[i]);
    }
    while (m--)
    {
        cin>>x;
        if (p[n-1]<=0&&mp[n-1]<x)
        {
            cout<<"-1 ";
            continue;
        }
        if (mp[n-1]<x)
        {
            l=0;r=INF;
            while (l<r)
            {
                mid=l+(r-l)/2;
                if (p[n-1]*mid+mp[n-1]>=x)
                    r=mid;
                else
                    l=mid+1;
            }
        }
        else
            l=0;
        c=l;
        l=0;r=n-1;
        while (l<r)
        {
            mid=l+(r-l)/2;
            if (p[n-1]*c+mp[mid]>=x)
                r=mid;
            else
                l=mid+1;
        }
        cout<<1LL*c*n+l<<" ";
    }
    cout<<"\n";

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