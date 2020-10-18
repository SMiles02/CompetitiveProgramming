#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

ll f[26];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    ll ans=1e18,cur;
    for (auto i : s)
        ++f[(i-'A')];
    for (int i=0;i<100001;++i)
    {
        cur=0;
        for (ll j=0;j<26;++j)
            if (f[j])
                cur+=((j+1)*abs(i-f[j]));
        ans=min(ans,cur);
    }
    cout<<ans;
    return 0;
}