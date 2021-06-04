#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

set<ll> v[3];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll k,ans;
    char c;
    cin>>n;
    n*=2;
    while (n--)
    {
        cin>>k>>c;
        if (c=='R')
            v[0].insert(k);
        else if (c=='G')
            v[1].insert(k);
        else
            v[2].insert(k);
    }
    if ((sz(v[0])%2==0)&&(sz(v[1])%2==0)&&(sz(v[2])%2==0))
    {
        cout<<0;
        return 0;
    }
    ans=1e18;
    for (int i=0;i<3;++i)
        for (int j=i+1;j<3;++j)
            if ((sz(v[i])&1)&&(sz(v[j])&1))
            {
                for (auto x : v[i])
                {
                    if (v[j].lower_bound(x)!=v[j].end())
                        ans=min(ans,abs(x-*(v[j].lower_bound(x))));
                    if (v[j].lower_bound(x)!=v[j].begin())
                        ans=min(ans,abs(x-*(--v[j].lower_bound(x))));
                }
            }
    cout<<ans;
    return 0;
}