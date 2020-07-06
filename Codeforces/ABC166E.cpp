#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<ll,ll> m;
    ll n,ans=0,x;
    cin>>n;
    for (ll i=1;i<=n;++i)
    {
        cin>>x;
        ans+=m[i-x];
        ++m[x+i];
    }
    cout<<ans;
    return 0;
}