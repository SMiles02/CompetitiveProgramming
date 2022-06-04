#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

int f[200001], pF[200001], p[200001];

void solve()
{
    int n,k,ans,cur;
    cin>>n;
    ans=n;
    map<int,int> m;
    for (int i=0;i<=n;++i)
        f[i]=0;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        if (m[k])
            --f[m[k]];
        ++f[++m[k]];
    }
    for (int i=1;i<=n;++i)
    {
        pF[i]=pF[i-1]+f[i];
        p[i]=p[i-1]+f[i]*i;
    }
    for (int i=1;i<=n;++i)
    {
        cur=p[i-1];
        cur+=p[n]-p[i];
        cur-=i*(pF[n]-pF[i]);
        //cout<<ans<<"\n";
        //cout<<i<<": "<<cur<<"\n";
        ans=min(ans,cur);
    }
    cout<<ans<<"\n";
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