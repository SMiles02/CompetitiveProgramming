#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,l=1;
    ll m;
    cin>>n>>k>>m;
    vector<int> up(n+1), tp(n+1), ans(n+1);
    vector<ll> a(n+1);
    iota(ans.begin(), ans.end(), 0);
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        while (l+1<=i&&l+k+1<=n)
        {
            if (max(abs(a[i]-a[l]),abs(a[l+k]-a[i]))<=max(abs(a[i]-a[l+1]),abs(a[l+k+1]-a[i])))
                break;
            ++l;
        }
        if (a[i]-a[l]>=a[l+k]-a[i])
            up[i]=l;
        else
            up[i]=l+k;
    }
    while (m)
    {
        if (m&1)
            for (int i=1;i<=n;++i)
                ans[i]=up[ans[i]];
        for (int i=1;i<=n;++i)
            tp[i]=up[up[i]];
        for (int i=1;i<=n;++i)
            up[i]=tp[i];
        m/=2;
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}