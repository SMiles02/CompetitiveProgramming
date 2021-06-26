#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

ll f(ll a)
{
    return (a*(a+1))/2;
}

ll divSum(int n, int m)
{
    return f(n/m-1)*m+(n/m)*(n%m+1);
}

void solve()
{
    int n,m,l,r,mid;
    cin>>n>>m;
    if (n>m)
    {
        cout<<"-1\n";
        return;
    }
    l=1;r=n;
    while (l<r)
    {
        mid=l+(r-l)/2;
        if (divSum(n+mid-1,mid)<=m)
            r=mid;
        else
            l=mid+1;
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