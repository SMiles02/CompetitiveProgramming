#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ll l=1,r=1LL*n*n,m,c;
    while (l<r)
    {
        m=l+(r-l)/2;
        c=0;
        for (int i=1;i<=n;++i)
            c+=min(m/i,n);
        if (c<(1LL*n*n+1)/2)
            l=m+1;
        else
            r=m;
    }
    cout<<l;
    return 0;
}